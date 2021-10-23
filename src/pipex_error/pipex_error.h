/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_error.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 21:54:58 by lrocigno          #+#    #+#             */
/*   Updated: 2021/10/23 01:59:20 by lrocigno         ###   ########.fr       */
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

# include "../pipex/pipex.h"

# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <libft.h>

pid_t	pipex_error_fork(void);
void	pipex_error_check_query(t_query *query, int n_cmds);

#endif
