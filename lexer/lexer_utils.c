/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 14:09:56 by abellakr          #+#    #+#             */
/*   Updated: 2022/05/26 14:57:18 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// ----------------------------------------- 
int		count_syntax(char *buffer)
{
	int count;
	int i;
	
	i = 0;
	count = 0;
	while(buffer[i] != '\0')
	{
		if(check_if_operator(buffer[i]) == 0)
		{
			count++;
			while(check_if_operator(buffer[i]) == 0)
						i++;
		}
		else if(check_if_operator(buffer[i]) == 1)
			// check_operator_validation();
		
		i++;
	}
	return(0);
}
// --------------------------------------------- check if character is an operator or not
int check_if_operator(char s)
{
	if(ft_strchr(OPERATORS, s) != NULL)
		return(1);
	return(0);
}
// -------------------------------------------- check if syntax of operator is correct or not
int check_operator_validation(char first_char, char second_char, char third_char)
{
	
}