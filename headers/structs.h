/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 13:03:28 by abellakr          #+#    #+#             */
/*   Updated: 2022/06/11 02:32:38 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef STRUCTS_H
# define STRUCTS_H
//----------------------------lexer  data
typedef struct data
{
	struct data *prev;
	char *str;
	int token;
	struct data *next;
}t_data;
//---------------------------------------- minishell data
// typedef struct s_shell
// {
	
// }
#endif