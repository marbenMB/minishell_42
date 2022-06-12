/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 14:11:13 by abellakr          #+#    #+#             */
/*   Updated: 2022/06/11 12:18:59 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//------------------------- ANALYSE BUFFER
t_data	*analyse_buffer(char *buffer)
{
	t_data *data;
	char *str;
	t_data *back_up;

	data = NULL;
	str = buffer;
	free(buffer);
	buffer = ft_strtrim(str, " ");
	if (check_syntax_error(buffer) == 1)
	{
		write (2, "syntax error", 12);
		return(NULL);
	}		
	if(data_reconization(buffer, &data) == 1)
	{
		if (data)
		{
			back_up = data;
			while (data)
			{
				back_up = (data)->next;
				free(data->str);
				free(data);
				data = back_up;
			}
		}
		write (2, "syntax error", 12);
		return(NULL);
	}
	free(buffer);
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
int	data_reconization(char *buffer, t_data **data)
{
	while(*buffer)
	{
		if(ft_is_operator(*buffer) == 1)
		{
			if (operator_type(&buffer, data) == 1)
				return (1);
		}
		else if(ft_is_operator(*buffer) == 0)
		{
			if(word_token(&buffer, data) == 1)
				return (1);
		}
	}
	return (0);
}
//----------------------------------------------------------- woed
int 	word_token(char **buffer, t_data **data)
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
	return (0);
}
//-------------------------------------------------- check operator type and save operator and data
int	operator_type(char **buffer, t_data **data)
{
	if (**buffer == '|')
	{
		if (pipe_data(buffer, data) == 1)
			return (1);
	}
	else if(**buffer == '<' && *(*buffer + 1) == '<')
		save_operator_data(buffer, data, HEREDOC);
	else if (**buffer == '>' && *(*buffer + 1) == '>')
		save_operator_data(buffer, data, APND);
	else if(**buffer == '<' && *(*buffer + 1) != '<')
		save_operator_data(buffer, data, RIP);
	else if(**buffer == '>' && *(*buffer + 1) != '>')
		save_operator_data(buffer, data, ROP);
	return (0);
}
//------------------------------------------------------------ store pipe
int	pipe_data(char **buffer, t_data **data)
{
	ft_lstadd_back_lexer(data, ft_lstnew_lexer("|", PIPE));
	(*buffer)++;
	while(**buffer == ' ')
		(*buffer)++;
	if(**buffer == '|')
		return (1);
	return (0);
}
//--------------------------------------------------------- other operators data
int	save_operator_data(char **buffer, t_data **data, int flag)
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
	return (0);
}
