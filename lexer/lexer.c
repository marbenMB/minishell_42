/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 14:11:13 by abellakr          #+#    #+#             */
/*   Updated: 2022/06/11 03:10:20 by abellakr         ###   ########.fr       */
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
		// check syntax error
		write (2, "syntax error", 12);
		return(NULL);
	}		
	data_reconization(buffer, &data);	// save data and tokens in lincked list
	// check error logic
	while(1)
	{
		printf("data:%10s	| token:%8d\n", data->str, data->token);
		if (data->next == NULL)
			break;
		else if(data->next != NULL)
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
//***************************************************************************************************************** logic 1 dial lexer
//--------------------------------------------- save data and token reconization
// void	data_reconization(char *buffer, t_data **data)
// {
// 	while(*buffer)
// 	{
// 		if(*buffer == ' ')
// 			buffer++;
// 		else if(*buffer == 34 || *buffer == 39)
// 			// alloc word inside quotes and not to scape space
// 			word_inside_quotes(&buffer, data, *buffer);
// 		else if(ft_is_operator(*buffer) == 1)
// 			// check wish type of operartors and alloc for it 
// 			operator_type(&buffer, data);
// 		else
// 			// alloc for word witout space
// 			word_token(&buffer, data);
// 	}
// }
// //------------------------------------------ word data inside quotes
// void	word_inside_quotes(char **buffer, t_data **data, char quote)
// {
// 	int i;
// 	char *str;

// 	i = 2;
// 	str = *buffer;
// 	(*buffer)++;
// 	while(**buffer != quote)
// 	{
// 		i++;
// 		(*buffer)++;
// 	}
// 	(*buffer)++;
// 	str = ft_substr(str, 0, i);
// 	ft_lstadd_back_lexer(data, ft_lstnew_lexer(str, 7));
// 	free(str);
// }
// //-------------------------------------------------- check operator type and save operator and data
// void	operator_type(char **buffer, t_data **data)
// {
// 	if (**buffer == '|')
// 	{
// 		ft_lstadd_back_lexer(data, ft_lstnew_lexer("|", PIPE));
// 		(*buffer)++;
// 	}
// 	else if(**buffer == '<' && *(*buffer + 1) == '<')
// 	{
// 		ft_lstadd_back_lexer(data, ft_lstnew_lexer("<<", LIMITER));
// 		(*buffer) += 2;
		
// 	}
// 	else if (**buffer == '>' && *(*buffer + 1) == '>')
// 	{
// 		ft_lstadd_back_lexer(data, ft_lstnew_lexer(">>", APND));
// 		(*buffer) += 2;
// 	}
// 	else if(**buffer == '<' && *(*buffer + 1) != '<')
// 	{
// 		ft_lstadd_back_lexer(data, ft_lstnew_lexer("<", RIP));
// 		(*buffer)++;
// 	}
// 	else if(**buffer == '>' && *(*buffer + 1) != '>')
// 	{
// 		ft_lstadd_back_lexer(data, ft_lstnew_lexer(">", ROP));
// 		(*buffer)++;
// 	}
// }
// //----------------------------------------------------------- woed
// void 	word_token(char **buffer, t_data **data)
// {
// 	int i;
// 	char *str;
	
// 	i = 0;
// 	str = *buffer;
// 	while(**buffer != '\0')
// 	{
// 		i++;
// 		(*buffer)++;
// 		if((**buffer == '"') || (**buffer == '\'') || (**buffer == ' ') || (ft_is_operator(**buffer) == 1))
// 			break;
// 	}
// 	str = ft_substr(str, 0, i);
// 	ft_lstadd_back_lexer(data, ft_lstnew_lexer(str, 7));
// 	free(str);
// }
// ******************************************************************************************************************************************* 