/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_error.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 21:54:58 by lrocigno          #+#    #+#             */
/*   Updated: 2021/10/27 18:05:48 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Deal with errors.
**
** Some of the functions in pipex_utils also do error management, but the main
** diference is that while the pipex_utils never emits error messages, the error
** module emits, and also, utils generate what is needed to program work
** properly, error exists to protect the program.
*/

#ifndef PIPEX_ERROR_H
# define PIPEX_ERROR_H

# include <pipex.h>
# include <errno.h>

void	pipex_error_check_query(t_query *query);
void	pipex_error_check_argc(int argc);
pid_t	pipex_error_try_fork(void);
int		pipex_error_try_execve(t_query *query, int p);
int		pipex_error_try_open(char *pathname, int flags, mode_t mode);

#endif
