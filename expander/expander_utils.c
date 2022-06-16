/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 08:05:36 by abellakr          #+#    #+#             */
/*   Updated: 2022/06/15 15:31:11 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//------------------------ create  a new node in my list
t_env	*ft_lstnew_expander(char *var, char *value)
{
	t_env	*element;

	element = (t_env *)malloc(sizeof(t_env));
	if (!element)
		return (0);
	element->var = ft_strdup(var);
	element->value = ft_strdup(value);
	element->next = NULL;
	element->prev = NULL;
	return (element);
}

//------------------------------------ ft_add_back
void	ft_lstadd_back_expander(t_env **lst, t_env *new)
{
	t_env	*lastnode;

	if (*lst == NULL)
	{
		(*lst) = new;
		return ;
	}
	lastnode = ft_lstlast_expander(lst);
	new->prev = lastnode;
	lastnode->next = new;
}

//---------------------------------------- find last node int list 
t_env	*ft_lstlast_expander(t_env **lst)
{
	t_env	*backup;

	backup = *lst;
	if (backup == NULL)
		return (NULL);
	while (backup->next != NULL)
		backup = backup->next;
	return (backup);
}
//------------------------------------------------------ find the correct value to the env variable
char	*var_finder(char *var, t_env *env)
{
	t_env *backup;
	char *correct_value;

	backup = env;
	correct_value = NULL;
	while(backup)
	{
		if(var == backup->var)
		{
			correct_value =  ft_strdup(backup->value);
			break;
		}
		backup = backup->next;
	}
	return(correct_value);
}