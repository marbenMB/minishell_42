/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 14:11:13 by abellakr          #+#    #+#             */
/*   Updated: 2022/06/05 17:33:28 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//------------------------- ANALYSE BUFFER
int	analyse_buffer(char *buffer, t_data **data)
{
	data = NULL;
	if (check_syntax_error(buffer) == 1)
		write (2, "syntax error", 12);
	// save data and tokens in lincked list
	// check syntac logic 
	return(0);
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
	buffer = ft_strtrim(buffer, " ");
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
// //--------------------------------------------- save data and token reconization
void	data_reconization(char *buffer, t_data **data)
{
	int i;

	i = 0;
	while(buffer[i])
	{
		if(!ft_is_operator(buffer[i]))
		{
			// check if space or double quote and save data
		}
		else if (ft_is_operator(buffer[i]))
		{
						
		}
		else if(buffer[i] == '\0')
			break;
	}
}