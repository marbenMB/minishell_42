/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 13:13:17 by abellakr          #+#    #+#             */
/*   Updated: 2022/06/15 13:54:58 by abellakr         ###   ########.fr       */
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
		// send node to check availabe variables to be expanded
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
	t_env *hhhh = env;
	hhhh = NULL ;
	new = ft_strdup(str);
	while(new[i])
	{
		quotes_checker(new[i], &quote_type);
		if((new[i] == '"' && quote_type != '\'') || (new[i] == '\'' && quote_type != '"'))
		{
			ft_memmove(&new[i], &new[i + 1], ft_strlen(new) - i);
			i--;
		} 
		i++;
	}
	return (new);
}
//-------------------------------------------------
void	quotes_checker(char quote, char *quote_type)
{
	if((quote == '"' && *quote_type == '"') || (quote == '\'' && *quote_type == '\''))
		*quote_type = 0;
	else if((quote == '"' && *quote_type == 0) || (quote == '\'' && *quote_type == 0))
		*quote_type = quote;	
}