/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 13:59:05 by abellakr          #+#    #+#             */
/*   Updated: 2022/05/26 14:21:13 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int ac, char  **av, char **env)
{
	char *buffer;

	ac = 0;
	av = NULL;
	env = NULL;
	while (1)
	{
		buffer = readline (" \033[0;32m ➜   minishell  :  \033[0;37m");
	}
	free(buffer);
	return(0);
}
// TODO abdellah : main function that checks if syntax is valid or not , then token this syntax
// TODO abdellah :  hna khadi ndir whd function dial check quotes wach msalyiin ola la 
// TODO abdellah : khadi ndir whd function tchof lia wach operator valid or not 
// TODO abdellah : operator homa < << >> || | && 
// TODO abdellah : "" '' --> cas dial la kant "cmd" token cmd 