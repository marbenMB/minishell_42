/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 13:58:20 by abellakr          #+#    #+#             */
/*   Updated: 2022/06/10 03:58:34 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef MINISHELL_H
# define MINISHELL_H
// ************************************* includes
# include "headers/includes.h"
# include "headers/macros.h"
# include "headers/structs.h"
// *************************************** lexer 
//------------------ utils
t_data	*ft_lstnew_lexer(char *data, int token);
void	ft_lstadd_back_lexer(t_data **lst, t_data *new);
t_data	*ft_lstlast_lexer(t_data **lst);
//------------------ lexer functions
int check_syntax_error(char *buffer);
int	ft_is_operator(char c);
int ft_special_char(char c);
int check_the_operator(char c);
t_data	*analyse_buffer(char *buffer);
void	data_reconization(char *buffer, t_data **data);
void	word_inside_quotes(char **buffer, t_data **data, char quote);
void	operator_type(char **buffer, t_data **data);
void 	word_token(char **buffer, t_data **data);
#endif

// TODO : 
// first parte is token operators
// token others as words and skip space exepte inside double quotes
// check word tokens to 3 partes :
// 1 : filename
// 2 : dollar word 
// 3 : simple word
//---------------------------------------
// need to handel $ and ? case in spaecial char inside in outside "" 
// add history 
//----------------------------------
// norme some functions and hande
// check error logic function
// moraja3a ldakchi li khsna ndiro 
// nchofo blan dial expander
