/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_error_try_fork.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 22:53:51 by lrocigno          #+#    #+#             */
/*   Updated: 2021/10/27 13:45:42 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_error.h"

/*
** Protect the program against an error while forking the process.
**
** In case fork successfully create a child, it returns the pid of the new
** process (or zero, for the child). Case it fails, emit a error message and
** then exit the program.
*/

pid_t	pipex_error_try_fork(void)
{
	pid_t	ret;

	ret = fork();
	if (ret < 0)
	{
		perror("Problem while forking");
		exit(0);
	}
	return (ret);
}
