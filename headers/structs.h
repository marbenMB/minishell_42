/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 13:03:28 by abellakr          #+#    #+#             */
/*   Updated: 2022/05/30 13:37:18 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H
//---------------------------------------------- lexer  data
typedef struct data
{
	char *data;
	int token;
	struct data *next;
}t_data;
#endif