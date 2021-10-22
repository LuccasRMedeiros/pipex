/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_error_fork.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 18:27:31 by lrocigno          #+#    #+#             */
/*   Updated: 2021/10/21 18:59:14 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Protect the program against an error while forking the process.
**
** In case fork successfully create a child, it returns the pid of the new
** process (or zero, for the child). Case it fails, emit a error message and
** then exit the program.
*/

#include "pipex_error"

pid_t	pipex_error_fork(void)
{
	pid_t	ret;

	ret = fork();
	if (ret < 0)
	{
		perror("Pipex error on fork:");
		exit(0);
	}
	return (ret);
}
