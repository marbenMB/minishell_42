/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 13:13:17 by abellakr          #+#    #+#             */
/*   Updated: 2022/06/18 06:59:21 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

//----------------------------------------------------- exapande data variables
void	expander(t_data **data, t_env *env)
{
	t_data *backup;
	char *new_str;

	backup = *data;
	new_str = NULL;
	while (backup)
	{
		new_str = expande_str_data(backup->str, env);
		free(backup->str);
		backup->str = new_str;
		backup = backup->next;
	}
}
//------------------------------------------------------
char	*expande_str_data(char *str, t_env *env)
{
	int i;
	char quote_type;
	char *new;

	i = 0;
	quote_type = 0;
	new = ft_strdup(str);
	while(new[i])
	{
		quotes_checker(new[i], &quote_type);
		if((new[i] == '"' && quote_type != '\'') || (new[i] == '\'' && quote_type != '"'))
		{
			ft_memmove(&new[i], &new[i + 1], ft_strlen(new) - i);
			i--;
		} 
		if(new[i] == '$' && quote_type != '\'')
			i = dollar_var(&new, env);
		i++;
	}
	return (new);
}

