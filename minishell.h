/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 13:58:20 by abellakr          #+#    #+#             */
/*   Updated: 2022/06/12 06:56:27 by abellakr         ###   ########.fr       */
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
//---------------------------------- token and save data
int	data_reconization(char *buffer, t_data **data);
int	operator_type(char **buffer, t_data **data);
int word_token(char **buffer, t_data **data);
int	pipe_data(char **buffer, t_data **data);
int	save_operator_data(char **buffer, t_data **data, int flag);
#endif

// TODO : 
// norme 
// leaks -> valgrind
// expander :
	// double quptes "" and single quotes ''
	// $ vraibles
	// export problem with spaces !!
// check files accebility
// rio problem in the last line
// split cmds for the executer in struct with thier flag separated
// $ ? cases
