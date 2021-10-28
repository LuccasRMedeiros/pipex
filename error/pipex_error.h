/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_error.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 21:54:58 by lrocigno          #+#    #+#             */
/*   Updated: 2021/10/28 11:27:00 by lrocigno         ###   ########.fr       */
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

pid_t	pipex_error_try_fork(void);
int		pipex_error_try_execve(t_query *query, int p);
int		pipex_error_try_open(char *pathname, int flags, mode_t mode);

#endif
