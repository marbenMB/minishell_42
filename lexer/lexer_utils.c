/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 13:34:54 by abellakr          #+#    #+#             */
/*   Updated: 2022/06/07 04:08:49 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//------------------------------------------------------------ create  a new node in my list
t_data	*ft_lstnew_lexer(char *data, int token)
{
	t_data	*element;

	element = (t_data *)malloc(sizeof(t_data));
	if (!element)
		return (0);
	element->data = data;
	element->token = token;
	element ->next = NULL;
	return (element);
}
//------------------------------------ ft_add_back
void	ft_lstadd_back_lexer(t_data **lst, t_data *new)
{
	t_data	*lastnode;

	if (*lst == NULL)
	{
		(*lst) = new;
		return ;
	}
	else if (*lst != NULL)
	{
		lastnode = ft_lstlast_lexer(lst);
		lastnode->next = new;
	}
}

//---------------------------------------- find last node int list 
t_data	*ft_lstlast_lexer(t_data **lst)
{
	t_data	*backup;

	backup = *lst;
	if (backup == NULL)
		return (NULL);
	while (backup->next != NULL)
		backup = backup->next;
	return (backup);
}
//-----------------------------------------------
int	ft_is_operator(char c)
{
	if(ft_strchr("<>|", c))
		return 1;
	return 0;	
}
//-------------------------------------------------
int ft_special_char(char c)
{
	if (ft_strchr("\\#`[]!{};()*~&", c))
		return(1);
	return 0;
}