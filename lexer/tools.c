/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 08:35:24 by abellakr          #+#    #+#             */
/*   Updated: 2022/06/12 15:48:01 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//-------------------------------------------------- function free data
void	free_data(t_data **data)
{
	t_data	*back_up;

	if (*data)
	{
		back_up = *data;
		while (*data)
		{
			back_up = (*data)->next;
			free((*data)->str);
			free(*data);
			*data = back_up;
		}
	}
}
