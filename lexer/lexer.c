/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 14:11:13 by abellakr          #+#    #+#             */
/*   Updated: 2022/06/11 10:04:30 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//------------------------- ANALYSE BUFFER
t_data	*analyse_buffer(char *buffer)
{
	t_data *data;
	char *str;

	data = NULL;
	str = buffer;
	free(buffer);
	buffer = ft_strtrim(str, " ");
	if (check_syntax_error(buffer) == 1)
	{
		write (2, "syntax error", 12);
		return(NULL);
	}		
	data_reconization(buffer, &data);	// save data and tokens in lincked list
	while(data)
	{
		printf("data: (%s)	      |	token: (%5d)\n", data->str, data->token);
		data = data->next;
	}
	return(data);
}
// --------------------------------------------------------------------------- check syntax error 
int   check_syntax_error(char *buffer)
{
	size_t i;
	int d_quotes;
	int s_quotes;

	i = 0;
	d_quotes = 0;
	s_quotes = 0;
	if(buffer[i] == '|')
		return (1);
	while(buffer[i])
	{
		if(buffer[i] == '\'' && s_quotes == 0 && d_quotes == 0)
			s_quotes = 1;
		else if(buffer[i] == '\'' && s_quotes == 1)
			s_quotes = 0;
		if(buffer[i] == '"' && d_quotes == 0 && s_quotes == 0)
			d_quotes = 1;
		else if(buffer[i] == '"' && d_quotes == 1)
			d_quotes = 0;
		if(s_quotes == 0 && d_quotes == 0)
		{
			if(ft_special_char(buffer[i]))
				return (1);
			if(ft_is_operator(buffer[i]))
			{
				if(buffer[i] == '<' && buffer[i + 1] != buffer[i] && (ft_special_char(buffer[i + 1]) || ft_is_operator(buffer[i + 1])))
					return (1);
				if(buffer[i] == '>' && buffer[i + 1] != buffer[i] && (ft_special_char(buffer[i + 1]) || ft_is_operator(buffer[i + 1])))
					return (1);
				if(buffer[i] == '<' && buffer[i + 1] == '<' && (ft_special_char(buffer[i + 2]) || ft_is_operator(buffer[i + 2])))
					return (1);
				if(buffer[i] == '>' && buffer[i + 1] == '>' && (ft_special_char(buffer[i + 2]) || ft_is_operator(buffer[i + 2])))
					return (1);
				if (buffer[i] == '|' && buffer[i + 1] == '\0')
					return (1);
			}
		}
		i++;
	}
	if(s_quotes == 1|| d_quotes == 1)
		return (1);
	return (0);
}

// --------------------------------------------- save data and token reconization
void	data_reconization(char *buffer, t_data **data)
{
	while(*buffer)
	{
		if(ft_is_operator(*buffer) == 1)
			operator_type(&buffer, data);
		else if(ft_is_operator(*buffer) == 0)
			word_token(&buffer, data);
	}
}
//----------------------------------------------------------- woed
void 	word_token(char **buffer, t_data **data)
{
	int i;
	char *str1;
	char *str2;
	
	i = 0;
	str1 = *buffer;
	while(**buffer != '\0')
	{
		i++;
		(*buffer)++;
		if(ft_is_operator(**buffer) == 1)
			break;
	}
	str1 = ft_substr(str1, 0, i);
	str2 = ft_strtrim(str1, " ");
	ft_lstadd_back_lexer(data, ft_lstnew_lexer(str2, CMD_WORD));
	free(str1);
	free(str2);
}
//-------------------------------------------------- check operator type and save operator and data
void	operator_type(char **buffer, t_data **data)
{
	// handle pipe
	if (**buffer == '|')
		pipe_data(buffer, data);
	// handle herdoc
	else if(**buffer == '<' && *(*buffer + 1) == '<')
		save_operator_data(buffer, data, HEREDOC);
	// handle appand
	else if (**buffer == '>' && *(*buffer + 1) == '>')
		save_operator_data(buffer, data, APND);
	// handle rip
	else if(**buffer == '<' && *(*buffer + 1) != '<')
		save_operator_data(buffer, data, RIP);
		// handle rop
	else if(**buffer == '>' && *(*buffer + 1) != '>')
		save_operator_data(buffer, data, ROP);
}
//------------------------------------------------------------ store pipe
void	pipe_data(char **buffer, t_data **data)
{
	ft_lstadd_back_lexer(data, ft_lstnew_lexer("|", PIPE));
	(*buffer)++;
}
//--------------------------------------------------------- heredoc_data
void	save_operator_data(char **buffer, t_data **data, int flag)
{
	int i;
	char *str1;
	char *str2;
	i = 0;
	if(flag == HEREDOC || flag == APND)
		(*buffer) += 2;
	else if(flag == RIP || flag == ROP)
		(*buffer)++;
	while(**buffer == ' ')
		(*buffer)++;
	str1 = *buffer;
	while(**buffer != '\0')
	{
		i++;
		(*buffer)++;
		if(ft_is_operator(**buffer) == 1 || **buffer == ' ')
			break;
	}
	while(**buffer == ' ')
		(*buffer)++;
	str1 = ft_substr(str1, 0, i);
	str2 = ft_strtrim(str1, " ");
	ft_lstadd_back_lexer(data, ft_lstnew_lexer(str2, flag));
	free(str1);
	free(str2);
}
// echo -n "hello" | grep p << filename