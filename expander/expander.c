/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 13:13:17 by abellakr          #+#    #+#             */
/*   Updated: 2022/06/14 21:15:12 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

//----------------------------------------------------- exapande data variables
void	expander(t_data **data, t_env *env)
{
	t_data *backup;

	backup = *data;
	while (backup)
	{
		// send node to check availabe variables to be expanded
		backup = backup->next;
	}
}
//------------------------------------------------------ find the correct value to the env variable
char	*dollar_expander(char *var, t_env *env)
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
//--------------------------------------------- expande in  each node
void	check_data(t_data **node, t_env *env)
{
	t_data *backup;
	
	int double_quotes;
	int single_quotes;

	backup = *node;
}