/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 13:59:05 by abellakr          #+#    #+#             */
/*   Updated: 2022/06/11 10:45:40 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int ac, char  **av, char **env)
{
	char *buffer;
	t_data	*data;
	t_data *back_up;

	ac = 0;
	av = NULL;
	env = NULL;
	while (1)
	{
		buffer = readline ("\n \033[0;32m ➜ minishell  :  \033[0;37m");
		add_history(buffer);
		if(ft_strcmp(buffer, "exit") == 0)
			exit(0);
		data = analyse_buffer(buffer);
		free(buffer);
		if (data)
		{
			back_up = data;
			while (data)
			{
				back_up = (data)->next;
				free(data->str);
				free(data);
				data = back_up;
			}
		}
	}
	return(0);
}
