/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 14:11:13 by abellakr          #+#    #+#             */
/*   Updated: 2022/06/08 06:12:39 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//------------------------- ANALYSE BUFFER
t_data	*analyse_buffer(char *buffer)
{
	t_data *data;

	data = NULL;
	if (check_syntax_error(buffer) == 1)	// check syntax error
		write (2, "syntax error", 12);
	data_reconization(buffer, &data);	// save data and tokens in lincked list
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
	while(*buffer)
	{
		if(*buffer == 34 || *buffer == 39)
		{
			// alloc word inside quotes and not to scape space
			word_inside_quotes(&buffer, data, *buffer);
			printf("buffer fin wasl : %s\n",buffer);
		printf("------------------------------------------\n");
		}
		buffer++;
		// else if(ft_is_operator(*buffer) == 1)
		// 	// check wish type of operartors and alloc for it 
		// else if (*buffer == ' ')
		// else 
			// alloc for word witout space
	}
	

}
//------------------------------------------ word data inside quotes
void	word_inside_quotes(char **buffer, t_data **data, char quote)
{
	int i;
	static int j;
	char *str;

	i = 0;
	// j = 1;
	data = NULL;
	str = *buffer;
	(*buffer)++;
	while(**buffer != quote)
	{
		i++;
		(*buffer)++;
	}
	(*buffer)++;
	i++;
	str = ft_substr(str, 0, ++i);
	printf("lmra no : %d -> dakchi  li jbd lina : %s\n", j, str);
	printf("------------------------------------------\n");
	j++;

}
//------------------------------------------------------ test moving forward string with adress
	// buffer++;
	// while(*buffer != 34)
	// 	buffer++;
	// buffer++;
	// printf("\n-----------------------\n");
	// printf("%s", buffer);