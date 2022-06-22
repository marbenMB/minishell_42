/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_second_part.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 15:34:02 by abellakr          #+#    #+#             */
/*   Updated: 2022/06/22 21:30:50 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
//------------------------------------------------------------ 2  store pipe
int	pipe_data(char **buffer, t_data **data)
{
	ft_lstadd_back_lexer(data, ft_lstnew_lexer("|", PIPE));
	(*buffer)++;
	while (**buffer == ' ')
		(*buffer)++;
	if (**buffer == '|')
		return (1);
	return (0);
}