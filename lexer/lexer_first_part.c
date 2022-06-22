/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_first_part.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 14:11:13 by abellakr          #+#    #+#             */
/*   Updated: 2022/06/23 00:07:07 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//------------------------- ANALYSE BUFFER
t_data	*analyse_buffer(char *buffer)
{
	t_data	*data;
	t_data 	*final_list;
	char	*str;

	data = NULL;
	str = buffer;
	free(buffer);
	buffer = ft_strtrim(str, " ");
	if (check_syntax_error(buffer) == 1)
	{
		write (2, "syntax error", 12);
		return (NULL);
	}		
	if (data_reconization1(buffer, &data) == 1)
	{
		free_data(&data);
		write (2, "syntax error", 12);
		return (NULL);
	}
	// check simple command and organize it and put it in new lincked list
	final_list = simple_command_analyser(&data);
	free(buffer);
	return (final_list);
}

// ----------------------------------- save data and token reconization
int	data_reconization1(char *buffer, t_data **data)
{
	char quote;

	quote = 0;
	while (*buffer)
	{
		if (*buffer == '|')
		{
			if (pipe_data(&buffer, data) == 1)
				return (1);
		}
		else if (*buffer != '|')
		{
			if (*buffer == '"' || *buffer == '\'')
				quote = *buffer;
			if (word_token(&buffer, data, &quote) == 1)
				return (1);
		}
	}
	return (0);
}

//<----------------------------------------------------------->    word
int	word_token(char **buffer, t_data **data, char *quote)
{
	int		i;
	char	*str1;
	char	*str2;

	i = 0;
	str1 = *buffer;
	while (**buffer != '\0')
	{
		i++;
		(*buffer)++;
		quotes_checker(**buffer, quote);
		if (**buffer == '|' && *quote == 0)
			break ;
	}
	str1 = ft_substr(str1, 0, i);
	str2 = ft_strtrim(str1, " ");
	ft_lstadd_back_lexer(data, ft_lstnew_lexer(str2, SIMPLE_CMD));
	free(str1);
	free(str2);
	return (0);
}
//************************************************************************************************ new
//-------------------------------------------------------- NEW list 
t_data	*simple_command_analyser(t_data **data)
{
	t_data *backup;
	t_data *new_data;
	
	backup = *data;
	new_data = NULL;
	while(backup)
	{
		// SIMPLE COMMAND ORG
		if(backup->token == SIMPLE_CMD)
		{
			if (simple_command_check(&new_data, backup->str) == 1)
			{
				free_data(&new_data);
				free_data(data);
				return (NULL);		
			}
		}
			// add pipe token to list
		else if(backup->token == PIPE)
			ft_lstadd_back_lexer(&new_data, ft_lstnew_lexer("|", PIPE));
		backup = backup->next;	
	}
	free_data(data);
	return(new_data);
}
//--------------------------------------------------------------- simple command check
int	simple_command_check(t_data **new_data, char *simple_command)
{
	t_data *simple_command_list;
	t_data *head;

	simple_command_list = NULL;
	if (data_reconization2(simple_command, &simple_command_list) == 1)
	{
		free_data(&simple_command_list);
		write (2, "syntax error", 12);
		return (1);
	}
	// oranize simple commad
	head = simple_command_list;
	while(simple_command_list)
	{
		ft_lstadd_back_lexer(new_data, ft_lstnew_lexer(simple_command_list->str, simple_command_list->token));
		simple_command_list = simple_command_list->next;
	}
	simple_command_list = head;
	free_data(&simple_command_list);
	return (0);
}
//-------------------------------------------------------
int data_reconization2(char *simple_command, t_data **simple_command_list)
{
	
	char quote;

	quote = 0;
	while (*simple_command)
	{
		if (ft_is_operator(*simple_command) == 1)
		{
			if (operator_type(&simple_command, simple_command_list) == 1)
				return (1);
		}
		else if (ft_is_operator(*simple_command) == 0)
		{
			if (*simple_command == '"' || *simple_command == '\'')
				quote = *simple_command;
			if (cmd_token(&simple_command, simple_command_list, &quote) == 1)
				return (1);
		}
	}
	return (0);
}

//-------------------------------------------------------------------- cmd token
int	cmd_token(char **simple_command, t_data **simple_command_list, char *quote)
{
	int		i;
	char	*str1;
	char	*str2;

	i = 0;
	str1 = *simple_command;
	while (**simple_command != '\0')
	{
		i++;
		(*simple_command)++;
		quotes_checker(**simple_command, quote);
		if (ft_is_operator(**simple_command) == 1 && *quote == 0)
			break ;
	}
	str1 = ft_substr(str1, 0, i);
	str2 = ft_strtrim(str1, " ");
	ft_lstadd_back_lexer(simple_command_list, ft_lstnew_lexer(str2, CMD));
	free(str1);
	free(str2);
	return (0);
}
//---------------------------------------------------------------
// void oranize_simple_command_list(t_data **simple_command_list)
// {
//  	t_data *backup;

// 	 backup = *simple_command_list;
// 	 while (backup)
// 	 {
// 		 if(backup)
// 		backup = backup->next; 
// 	 }
// }