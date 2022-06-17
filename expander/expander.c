/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 13:13:17 by abellakr          #+#    #+#             */
/*   Updated: 2022/06/17 19:58:12 by abellakr         ###   ########.fr       */
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
	int i ;
	//-------------------------------------------- allocation in those functions
	after_var = after(*str);
	before_var = before(*str);
	var = in_var(*str, env);
	// printf("%s\n%s\n%s\n", before_var, var, after_var);
	//----------------------------------------------------------------------------
	free(*str);
	*str = ft_strjoin(before_var,var);
	i = ft_strlen(*str) - 1;
	*str = ft_strjoin(*str, after_var);
	free(before_var);
	free(var);
	free(after_var);
	return (i);
	// -------------------> check variable validation name <------------
}
//---------------------------- return str before variable --> fixed segfault
char *before(char *str)
{
	int i;
	char *before_var;

	i = 0;
	while(str[i] != '$' && str[i])
		i++;
	before_var = (char *)malloc((sizeof(char ) * i) + 1);
	i = 0;
	while(str[i] != '$' && str[i])
	{
		before_var[i] = str[i];
		i++;
	}
	before_var[i] = 0;
	return (before_var);
}
//------------------------------------------ return str after variable --> in progress
char *after(char *str)
{
	while(*str && *str != '$')
		str++;
	while(*str && *str != ' ' && *str != '"' && *str != '\'')
	{
		if(ft_is_operator(*str) == 1)
			break;
		str++;
	}
	return (ft_strdup(str));	
}
//------------------------------------------------------- return variable value
char *in_var(char *str, t_env *env)
{
	char *var;
	char *value;
	int i;
	
	var = NULL;
	i = 0;
	while(*str != '$')
		str++;
	str++;
	var = ft_strdup(str);
	while(*str && *str != ' ' && *str != '"' && *str != '\'' && ft_is_operator(*str) == 0)
	{
		i++;
		str++;
	}
	var = ft_substr(var, 0 ,i);
	value = var_finder(var, env);
	return (value);
		
		
}