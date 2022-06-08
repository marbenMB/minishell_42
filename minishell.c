/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 13:59:05 by abellakr          #+#    #+#             */
/*   Updated: 2022/06/07 22:45:47 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int ac, char  **av, char **env)
{
	char *buffer;
	t_data	*data;

	ac = 0;
	av = NULL;
	env = NULL;
	while (1)
	{
		buffer = readline ("\n \033[0;32m ➜ minishell  :  \033[0;37m");
		if(ft_strcmp(buffer, "exit") == 0)
			exit(0);
		data = analyse_buffer(buffer);
	}
	free(buffer);
	return(0);
}
// need to handel $ and ? case in spaecial char inside in outside "" 
// add history 
