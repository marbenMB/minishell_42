/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <mbenbajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 13:44:58 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/06/29 16:10:09 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

//	***********		Includes	*********** :
# include "../../minishell.h"

//	***********		DEFINES		*********** :
# define SUCC_STAT "0"
# define FAIL_STAT "1"
# define ERROR_STAT "-1"
# define NSFD "No such file or directory"
# define NVI "Not a valid identifier"

//	***********		Functions	*********** :
//	********		 ERRORS		******** :
void	error_cmd_arg(t_env **env, char *cmd, char *arg, char *msg);
//	********		 UTILS		******** :
	//	->	utils :
void	ft_status(t_env **env, char *stats);
t_env	*get_env_var(t_env **env, char *var_name);
	//	->	Proccessing :
int		proccess_cmd(t_shell *shell, char	*cmd);
int		proccess_buff(t_shell *shell);
	//	->	Checking :
void	check_in_env(t_shell *shell);
//	********		BUILTINS	******** :
//*	->	ft_echo :
int		ft_echo(t_shell *shell);
int		is_flag(char *word);
//*	->	ft_env :
int		ft_env(t_shell *shell);
//*	->	ft_pwd :
int		ft_pwd(t_shell *shell);
//*	->	ft_export :
//*			sort_env :
size_t	lst_size(t_env *lst);
size_t	tab_len(char **tab);
void	free_tab(char **tab);
char	**sort_tab(char **tab);
char	**get_var_tab(t_env *env);
void	print_env_var(char *var_name, char *value);
int		print_sorted_env(t_env *env);
//*			add_env_var :
int		add_env_var(t_env **env, char *var, char *value, int _if);
int		join_env_value(t_env **env, char *var, char *value, int _if);
char	*get_var_name(char *var_str);
t_env	*get_existed_var(t_env **env, char *var);
int		existed_var(t_env *env, char *var);
void	parse_var_str(t_env **env, char *var_str);
int		export_special_char(char c);
int		valid_name(char *var_str);
int		env_var(t_shell *shell);
int		ft_export(t_shell *shell);
//*	->	ft_cd :
int		ft_cd(t_shell *shell);
//*	->	ft_unset :
int		ft_unset(t_shell *shell);
//*	->	ft_exit :
int		ft_exit(t_shell *shell);
#endif
