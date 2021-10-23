/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 15:36:13 by lrocigno          #+#    #+#             */
/*   Updated: 2021/10/23 01:59:20 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

#include "pipex_utils/pipex_utils.h"
#include "pipex_error/pipex_error.h"

/*
** Parent execute the last command in query.
**
** The input for the last command will be read from the end[1] that were pipe()d
** and because of this behavior, we need to wait the child terminates.
*/

static void parent(t_query *query, pid_t child_pid)
{
	//TODO
	waitpid(child_pid);
	return ;
}

/*
** Child execute the first command in query.
*/

static void child(t_query *query)
{
	//TODO
	pipex_utils_redir(fd, STDIN_FILENO)
	return ;
}

/* 
** Main function.
**
** To execute the commands in the pipe we use execve. The execve function
** substitute the process in execution with the new one, so we need to fork the
** main process in order to process each command output properly.
**
** The main function splits into two functions, child, which refers to the child
** process created by the fork, and parent that refers to the process that was
** fork()ed.
**
** When we fork() a process, it returns a number that refer to the child process
** identification (pid), for the child nothing is returned, thanks to that we
** can identify who's the parent process and who's the child process.
*/

int	main(int argc, char **argv, char **env)
{
	t_query		*query;
	pid_t		child_pid;

	ft_bzero(query, 1);
	query->header = pipex_utils_set_header(envp);
	query->cmds = pipex_utils_set_cmds(argc, argv, envp[3]);
	pipex_error_check_query(query, argc - 2);
	child_pid = pipex_error_fork();
	if (!child_pid)
	{
		child_pid = pipex_error_fork();
		parent(fds[0], argv, env, child_pid);
	}
	if (!child_pid)
		child(fd[1], argv, env);
	return (0);
}
