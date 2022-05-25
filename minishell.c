/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 13:59:05 by abellakr          #+#    #+#             */
/*   Updated: 2022/05/25 16:20:37 by abellakr         ###   ########.fr       */
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
		big_split(buffer);
	}
	free(buffer);
	return(0);
}