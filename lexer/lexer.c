/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 14:11:13 by abellakr          #+#    #+#             */
/*   Updated: 2022/06/07 04:15:54 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//------------------------- ANALYSE BUFFER
int	analyse_buffer(char *buffer, t_data **data)
{
	if (check_syntax_error(buffer) == 1)
		write (2, "syntax error", 12);
	// save data and tokens in lincked list
	data_reconization(buffer, data);
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
	t_data *list = *data;
	while(*buffer != '\0')
	{
		if(*buffer == '\"' || *buffer == '\'')
		{
			// alloc word inside quotes and not to scape space
			word_inside_quotes(&buffer, &list, *buffer);
		}
		// else if(ft_is_operator(*buffer) == 1)
		// 	// check wish type of operartors and alloc for it 
		// else if (*buffer == ' ')
			buffer++;
		// else 
			// alloc for word witout space
	}
		printf("%s", list->data);
}
//------------------------------------------ word data inside quotes
void	word_inside_quotes(char **buffer, t_data **data, char quote)
{
	char *str;
	t_data *backup;
	t_data *list;
	
	str = ft_strdup(*buffer);
	list = *data;
	while(**buffer && **buffer != quote)
	{
		str = ft_strjoin(str, *buffer);
		buffer++;
	}
	backup = ft_lstnew_lexer(str, 7);
	ft_lstadd_back_lexer(&list, backup);
}
//-------------------------------------------------------- check wish operator and alloc for it
// void	operator_validation(char **buffer, t_data *data)
// {
// 	if()
// }