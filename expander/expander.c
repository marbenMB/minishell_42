/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 13:13:17 by abellakr          #+#    #+#             */
/*   Updated: 2022/06/27 09:08:40 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

//----------------------------------------------------- exapande data variables
void	expander(t_shell *data_shell)
{
	t_data *backup;
	char *new_str;

	backup = data_shell->data;
	new_str = NULL;
	while (backup)
	{
		if(backup->token != 8)
		{
			new_str = expande_str_data(backup->str, data_shell->env, backup->token);
			free(backup->str);
			backup->str = new_str;
		}
		backup = backup->next;
	}
	backup = data_shell->data;
	while(backup)
	{
		if(backup->token == 8)
			// function to put data in 2D array 
			command_filler(backup->str, data_shell->cmd);
		backup = backup->next;
	}
}
//------------------------------------------------------
char	*expande_str_data(char *str, t_env *env, int token)
{
	int i;
	char quote_type;
	char *new;

	i = 0;
	quote_type = 0;
	new = ft_strdup(str);
	while(new[i])
	{
		quotes_checker(new[i], &quote_type);
		if((new[i] == '"' && quote_type != '\'') || (new[i] == '\'' && quote_type != '"'))
		{
			ft_memmove(&new[i], &new[i + 1], ft_strlen(new) - i);
			i--;
		} 
		if(token != 4)
		{
			if(new[i] == '$' && quote_type != '\'')
				i = dollar_var(&new, env);		
		}
		i++;
	}
	return (new);
}
////////////////////////////////////////////////////////////////////////////new 
void	command_filler(char *cmd, t_cmd *cmds_table)
{
	cmds_table = NULL;
	int words_number;
	
	words_number = words_counter(cmd);
	printf("\n%d\n", words_number);
	// count the number of words I have in the table 
	// alloc for those words
	// fill table of 2d array with those words
	// expande the 2d array table
	// add  the table to my list of tables	
}
//------------------------------------------
int words_counter(char *cmd)
{
	int count;
	char quote_type;

	quote_type = 0;
	count = 0;
	while(*cmd)
	{
		quotes_checker(*cmd, &quote_type);
		if(quote_type == 0)
		// function to count word witout quotes
			count_words_witout_quotes(&cmd, &count);
		// function to count word with quotes
		else if(quote_type != 0)
			count_words_with_quotes(&cmd, &count, &quote_type);
		// skip space
		if(quote_type == 0 && *cmd == ' ')
		{
			while(*cmd == ' ')
				cmd++;
		}
	}
	return(count);	
}
//---------------------------------------------------------- count words inside quotes
void	count_words_witout_quotes(char **cmd, int *count)
{
	while(**cmd)
	{
		(*cmd)++;
		if(**cmd == ' ' || **cmd == '\'' || **cmd == '"')
			break;
	}
	if(**cmd == ' ' || **cmd == '\0')
		(*count)++;
}
//---------------------------------------------------------- count words inside quotes
void	count_words_with_quotes(char **cmd, int *count, char *quote_type)
{
	while(**cmd)
	{
		(*cmd)++;
		if(**cmd == *quote_type)
			break;
	}
	quotes_checker(**cmd, quote_type);
	(*cmd)++;
	if((**cmd == ' ' || **cmd == '\0') && *quote_type == 0)
		(*count)++;
}