/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 13:58:20 by abellakr          #+#    #+#             */
/*   Updated: 2022/06/14 21:10:03 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef MINISHELL_H
# define MINISHELL_H
// ********************************************** includes
# include "headers/includes.h"
# include "headers/macros.h"
# include "headers/structs.h"
// *************************************** lexer 
//------------------ utils
t_data	*ft_lstnew_lexer(char *data, int token);
void	ft_lstadd_back_lexer(t_data **lst, t_data *new);
t_data	*ft_lstlast_lexer(t_data **lst);
//------------------ lexer functions
int		check_syntax_error(char *buffer);
int		ft_is_operator(char c);
int		ft_special_char(char c);
int		check_the_operator(char c);
t_data	*analyse_buffer(char *buffer);
int		operator_error(char *buffer, int i);
//-------------------- token and save data
int		data_reconization(char *buffer, t_data **data);
int		operator_type(char **buffer, t_data **data);
int		word_token(char **buffer, t_data **data);
int		pipe_data(char **buffer, t_data **data);
int		save_operator_data(char **buffer, t_data **data, int flag);
void	check_flag(char **buffer, int flag);
int		count_cmd_word_len(char **buffer);
//------------------------------ tools
void	free_data(t_data **data);
//*************************************************** expander
//--------------------------- utils
t_env	*ft_lstnew_expander(char *var, char *value);
void	ft_lstadd_back_expander(t_env **lst, t_env *new);
t_env	*ft_lstlast_expander(t_env **lst);
void	free_data2(t_env **env);
//---------------------------- get env
t_env	*get_env(char **env);
char *get_var(char *line);
char *get_value(char *line);
#endif

// TODO : 
// expander :
	// double quptes "" and single quotes ''
	// $ varaibles
	// export problem with spaces !!
// check files accebility
// rio problem in the last line and middle
// split cmds for the executer in struct with thier flag separated
// $ ? cases
// exit status cases save in 