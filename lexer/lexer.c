/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 14:11:13 by abellakr          #+#    #+#             */
/*   Updated: 2022/06/02 18:57:36 by abellakr         ###   ########.fr       */
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
	int d_quotes;
	int s_quotes;

	i = 0;
	d_quotes = 0;
	s_quotes = 0;
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
				write (2, "parse error1", 12);
			if(ft_is_operator(buffer[i]))
			{
				if(buffer[i] == '<' && buffer[i + 1] != buffer[i] && (ft_special_char(buffer[i + 1]) || ft_is_operator(buffer[i + 1])))
					write (2, "parse error4", 12);
				if(buffer[i] == '>' && buffer[i + 1] != buffer[i] && (ft_special_char(buffer[i + 1]) || ft_is_operator(buffer[i + 1])))
					write (2, "parse error5", 12);
				if(buffer[i] == '<' && buffer[i + 1] == '<' && (ft_special_char(buffer[i + 2]) || ft_is_operator(buffer[i + 2])))
					write (2, "parse error6", 12);
				if(buffer[i] == '>' && buffer[i + 1] == '>' && (ft_special_char(buffer[i + 2]) || ft_is_operator(buffer[i + 2])))
					write (2, "parse error7", 12);
				if (buffer[i] == '|' && (ft_is_operator(buffer[i + 1])))
					write (2, "parse error8", 12);
			}
		}
		i++;
	}
	if(s_quotes == 1|| d_quotes == 1)
		write (2, "parse error9", 12);
}
//-----------------------------------------------
int	ft_is_operator(char c)
{
	if(ft_strchr("<>|\"\'", c))
		return 1;
	return 0;	
}
//-------------------------------------------------
int ft_special_char(char c)
{
	if (ft_strchr("\\#`[]!{};()*?~&", c))
		return(1);
	return 0;	
}