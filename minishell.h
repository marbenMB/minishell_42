/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 13:58:20 by abellakr          #+#    #+#             */
/*   Updated: 2022/06/04 19:26:00 by abellakr         ###   ########.fr       */
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
#endif

// TODO : RETURN STATUS IN SYNTAX ERROR functions, TOKEN OPERTORS BUT NOT SKIP SPACE INSIDE D_QUOTES AND S_QUOTES
// check pipe caeses with operators in syntax error function 