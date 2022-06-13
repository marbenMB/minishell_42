/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 13:59:05 by abellakr          #+#    #+#             */
/*   Updated: 2022/06/13 08:34:38 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **env)
{
	// char	*buffer;
	t_shell	shell;

	if(env == NULL)
		return (write(2, "empty env", 9) ,1);
	ac = 0;
	av = NULL;
	// get env variables
	shell.env = get_env(env);
	while(shell.env)
	{
		printf("%s=%s\n", shell.env->var, shell.env->value);
		shell.env = shell.env->next;
	}
	// while (1)
	// {
	// 	buffer = readline ("\n \033[0;32m ➜ minishell  :  \033[0;37m");
	// 	add_history(buffer);
	// 	if (ft_strcmp(buffer, "exit") == 0)
	// 		exit(0);
	// 	shell.data = analyse_buffer(buffer);
	// 	free_data(&(shell.data));
	// }
	return (0);
}
//----------------------------------------------- afkar
// echo -n "hello" | grep p << filename
//  ls | grep "hello" >> out > file// leaks
		// -------------------------------- print data