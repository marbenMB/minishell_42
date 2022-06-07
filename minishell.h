/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 13:58:20 by abellakr          #+#    #+#             */
/*   Updated: 2022/06/07 03:35:54 by abellakr         ###   ########.fr       */
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
int	analyse_buffer(char *buffer, t_data **data);
int check_syntax_error(char *buffer);
int	ft_is_operator(char c);
int ft_special_char(char c);
int check_the_operator(char c);
void	data_reconization(char *buffer, t_data **data);
void	word_inside_quotes(char **buffer, t_data **data, char quote);
//--------------------------------------------------- test  functions
void	ft_test(char **buffer);
#endif

// TODO : 
	// first parte is token operators
	// token others as words and skip space exepte inside double quotes
	// check word tokens to 3 partes :
	// 1 : filename
	// 2 : dollar word 
	// 3 : simple word