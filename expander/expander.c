/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 13:13:17 by abellakr          #+#    #+#             */
/*   Updated: 2022/06/16 11:58:39 by abellakr         ###   ########.fr       */
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
		if(new[i] == '$' && quote_type != '\'')
			i = dollar_var(&str, env);
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
//---------------------------------------------------- exapande dollar signe
int dollar_var(char **str, t_env *env)
{
	char *before_var;
	char *after_var;
	char *var;
	int i;
	char *backup = *str;

	before_var = before(backup);
	after_var = after(backup);
	var = in_var(backup, env);
	free(*str);
	*str = ft_strjoin(before_var,var);
	i = ft_strlen(*str) - 1;
	*str = ft_strjoin(*str, after_var);
	free(before_var);
	free(var);
	free(after_var);
	return (i);
	// check variable validation name
}
//---------------------------- return str before variable
char *before(char *str)
{
	int i;
	char *before_var;

	i = 0;
	before_var = NULL;
	while(str[i] != '$' && str[i])
	{
		before_var[i] = str[i];
		i++;
	}
	before_var = ft_strdup(before_var);
	return (before_var);
}
//------------------------------------------ return str after variable
char *after(char *str)
{
	int i;
	char *after_var;
	int j;

	i = 0;
	j = 0;
	after_var = NULL;
	while(str[i] != '$')
		i++;
	while(str[i] && str[i] != ' ' && ft_is_operator(str[i]) == 0)
		i++;
	while(str[i])
	{
		after_var[j] = str[i];
		j++;
		i++;
	}
	after_var = ft_strdup(after_var);
	return(after_var);
	
}
//------------------------------------------------------- return variable value
char *in_var(char *str, t_env *env)
{
	int i;
	int j;
	char *var;
	char *value;

	i = 0;
	j = 0;
	var = NULL;
	value = NULL;
	while(str[i] != '$')
		i++;
	i++;
	while(str[i] && str[i] != ' ' && ft_is_operator(str[i]) == 0)
	{
		var[j] = str[i];
		i++;
		j++;
	}
	var = ft_strdup(var);
	value = var_finder(var, env);
	free(var);
	return(value);
}