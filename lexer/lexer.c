/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 14:11:13 by abellakr          #+#    #+#             */
/*   Updated: 2022/06/01 13:50:11 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//------------------------- ANALYSE BUFFER
// void	analyse_buffer(char *buffer, t_data **data)
// {
// 	// check syntax error
// 	// save data and tokens in lincked list
// 	// check syntac logic 
// }
//--------------------------------- check syntax error
void  check_syntax_error(char *buffer)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while(buffer[i])
	{
		if(ft_is_operator(buffer[i]))
		{
			if(buffer[i] == '"')
			{
				i++;
				while(buffer[i] && buffer[i] != '"')
				{
					buffer++;
					i++;
				}
				if(i == ft_strlen(buffer))
					printf("parse error unclosed quote");		
			}
			if(buffer[i] == '\'')
			{
				i++;
				while(buffer[i] && buffer[i] != '\'')
				{
					buffer++;
					i++;
				}
				if(i == ft_strlen(buffer))
					printf("parse error unclosed quote");		
			}
			if(buffer[i] == '<' && buffer[i + 1 ] != buffer[i] && (ft_special_char(buffer[i + 1]) || ft_is_operator(buffer[i + 1])))
				printf("parse error");
			if(buffer[i] == '>' && buffer[i + 1 ] != buffer[i] && (ft_special_char(buffer[i + 1]) || ft_is_operator(buffer[i + 1])))
				printf("parse error");
			if(buffer[i] == '<' && buffer[i + 1] == '<' && (ft_special_char(buffer[i + 2]) || ft_is_operator(buffer[i + 2])))
				printf("parse error");
			if(buffer[i] == '>' && buffer[i + 1] == '>' && (ft_special_char(buffer[i + 2]) || ft_is_operator(buffer[i + 2])))
				printf("parse error");
			if (buffer[i] == '|' && (ft_special_char(buffer[i + 1])))
				printf("parse error");
		}
		i++;
	}
}
//-----------------------------------------------
int	ft_is_operator(char c)
{
	if(c == '<' || c == '>' || c == '|' || c == '"' || c == '\'')
		return 1;
	return 0;	
}
//-------------------------------------------------
int ft_special_char(char c)
{
	if (c == '\\' || c == '#' || c == '=' || c == '[' || c == ']' || c == '!' || c == '{' || c == '}' || c == ';' || c == '(' || c == ')' || c == '*' || c == '?' || c == '~' || c == '&')
		return 1;
	return 0;	
}
