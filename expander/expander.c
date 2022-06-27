/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 13:13:17 by abellakr          #+#    #+#             */
/*   Updated: 2022/06/27 14:27:41 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

//----------------------------------------------------- exapande data variables
void	expander(t_shell *data_shell)
{
	t_data *backup;
	char *new_str;
	char **cmd_tab;

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
			cmd_tab = command_filler(backup->str);
		backup = backup->next;
	}
	//---------------------------------- print and free tab
	// int i = 0;
	// while(cmd_tab[i])
	// {
	// 	printf("|%s|\n", cmd_tab[i]);
	// 	i++;
	// }
	// i = 0;
	// while(cmd_tab[i])
	// {
	// 	free(cmd_tab[i]);
	// 	i++;
	// }
	// free(cmd_tab);
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
//////////////////////////////////////////////////////////////////////////////////////NEW
//-------------------------- return 2D tan of cmd and its flags
char	**command_filler(char *cmd)
{
	int		words_number;
	char	**cmd_table;
	char	*rest;
	int i;
	
	i = 0;
	words_number = words_counter(cmd);
	cmd_table = (char **)malloc(words_number * sizeof(char *) + 1);
	rest = ft_strdup(cmd);
	while(i < words_number)
	{
		cmd_table[i] = word_finder(rest);
		rest = rest_finder(&rest);
		i++;
	}
	cmd_table[i] = NULL;
	free(rest);
	return (cmd_table);
}
//----------------------------------------------------------- find word
char *word_finder(char *string)
{
	int i;
	char quote_type;
	char *word;
	char *str;
	
	
	i = 0;
	quote_type = 0;
	str = ft_strdup(string);
	while(str[i])
	{
		quotes_checker(str[i], &quote_type);
		if(str[i] == ' ' && quote_type == 0)
			break;
		i++;
	}
	word = ft_substr(str, 0, i);
	free(str);
	return (word);
}
//---------------------------------------------------------------
char *rest_finder(char **string)
{
	int i;
	char quote_type;
	char *rest1;
	char *rest;
	char *str;
	
	i = 0;
	str = ft_strdup(*string);
	quote_type = 0;
	while(str[i])
	{
		quotes_checker(str[i], &quote_type);
		if(str[i] == ' ' && quote_type == 0)
			break;
		i++;
	}
	rest1 = ft_substr(str, i, ft_strlen(str));
	rest = ft_strtrim(rest1, " ");
	free(rest1);
	free(str);
	free(*string);
	return (rest);
}