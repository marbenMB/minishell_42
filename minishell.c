/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 13:59:05 by abellakr          #+#    #+#             */
/*   Updated: 2022/06/12 15:50:26 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **env)
{
	char	*buffer;
	t_data	*data;

	ac = 0;
	av = NULL;
	env = NULL;
	while (1)
	{
		buffer = readline ("\n \033[0;32m ➜ minishell  :  \033[0;37m");
		add_history(buffer);
		if (ft_strcmp(buffer, "exit") == 0)
			exit(0);
		data = analyse_buffer(buffer);
		// -------------------------------- print data
		while(data)
		{
			printf("data: (%s)	      |	token: (%5d)\n", data->str, data->token);
			data = data->next;
		}
		free_data(&data);
	}
	return (0);
}
// echo -n "hello" | grep p << filename
//  ls | grep "hello" >> out > file// leaks