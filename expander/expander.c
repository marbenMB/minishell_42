/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 13:13:17 by abellakr          #+#    #+#             */
/*   Updated: 2022/06/13 08:37:59 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

//----------------------------------------------- get env variable
t_env	*get_env(char **env)
{
	int i;
	int j;
	int k;
	int l;
	char *var;
	char *value;
	t_env *my_env;

	i = 0;
	my_env = NULL;
	var = NULL;
	value = NULL;
	while (env[i])
	{
		j = 0;
		k = 0;
		while(env[i][j] != '=')
		{
			k++;
			j++;
		}
		var = ft_substr(env[i], 0, k);
		j++;
		l = j;
		k = 0;
		while(env[i][j])
		{
			k++;
			j++;
		}
		value = ft_substr(env[i], l, k);
		ft_lstadd_back_expander(&my_env, ft_lstnew_expander(var, value));
		free(var);
		free(value);
		i++;
	}
	return(my_env);
}