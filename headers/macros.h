/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 13:03:25 by abellakr          #+#    #+#             */
/*   Updated: 2022/05/25 15:05:18 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H
//----------------------------------- operators
# define AND 0 // &&
# define OR 1 // ||
# define RIP 2 // <
# define ROP 3 // >
# define DELIMITER  4 // <<
# define APND 5 // >>
# define D_QUOTE 6 // ""
# define S_QUOTE 7 // ''
# define PIPE 15 // PIPE | 
//--------------------------------------------- build in commands
# define ECHO 8 // echo command 
# define CD 9 // cd command 
# define  PWD 10 // PWD  COMMAD
# define  EXPORT 11 // EXPORT  COMMAD
# define  UNSET 12 // UNSET  COMMAD
# define  ENV 13 // ENV  COMMAD
# define  EXIT 14 // EXIT  COMMAD

#endif