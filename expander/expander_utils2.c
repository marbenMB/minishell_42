/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 12:54:06 by abellakr          #+#    #+#             */
/*   Updated: 2022/06/27 12:55:31 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//------------------------------------------ count words in    string
int words_counter(char *cmd)
{
	int count;
	char quote_type;

	quote_type = 0;
	count = 0;
	while(*cmd)
	{
		quotes_checker(*cmd, &quote_type);
		if(quote_type == 0)
		// function to count word witout quotes
			count_words_witout_quotes(&cmd, &count);
		// function to count word with quotes
		else if(quote_type != 0)
			count_words_with_quotes(&cmd, &count, &quote_type);
		// skip space
		if(quote_type == 0 && *cmd == ' ')
		{
			while(*cmd == ' ')
				cmd++;
		}
	}
	return(count);	
}
//---------------------------------------------------------- count words inside quotes
void	count_words_witout_quotes(char **cmd, int *count)
{
	while(**cmd)
	{
		(*cmd)++;
		if(**cmd == ' ' || **cmd == '\'' || **cmd == '"')
			break;
	}
	if(**cmd == ' ' || **cmd == '\0')
		(*count)++;
}
//---------------------------------------------------------- count words inside quotes
void	count_words_with_quotes(char **cmd, int *count, char *quote_type)
{
	while(**cmd)
	{
		(*cmd)++;
		if(**cmd == *quote_type)
			break;
	}
	quotes_checker(**cmd, quote_type);
	(*cmd)++;
	if((**cmd == ' ' || **cmd == '\0') && *quote_type == 0)
		(*count)++;
}