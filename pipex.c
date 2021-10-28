/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 15:36:13 by lrocigno          #+#    #+#             */
/*   Updated: 2021/10/28 11:26:44 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/wait.h>

#include <pipex_utils.h>
#include <pipex_error.h>

/*
** Parent execute the last command in query.
**
** The input for the last command will be read from the end[1] that were pipe()d
** and because of this behavior, we need to wait the child terminates.
*/

static void parent(t_query *query, pid_t child_pid)
{
	int	status;

	waitpid(child_pid, &status, 0);
	pipex_utils_redir(query->fd_out, STDOUT_FILENO);
	pipex_utils_redir(query->fds[0], STDIN_FILENO);
	close(query->fds[1]);
	pipex_error_try_execve(query, 1);
	del_query(query);
}

/*
** Child execute the first command in query.
*/

static void child(t_query *query)
{
	pipex_utils_redir(query->fd_in, STDIN_FILENO);
	pipex_utils_redir(query->fds[1], STDOUT_FILENO);
	close(query->fds[0]);
	pipex_error_try_execve(query, 0);
	del_query(query);
	exit(0);
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

int	main(int argc, char **argv, char **envp)
{
	t_query		*query;
	pid_t		child_pid;

	if (argc != 5)
		exit(0);
	query = new_query(argc - 3);
	pipex_utils_set_cmds(query, argv + 2, envp);
	query->fd_in = pipex_error_try_open(argv[1], O_RDONLY, 0);
	query->fd_out = pipex_error_try_open(argv[argc - 1],
			O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (query->fd_in < 0 || query->fd_out < 0)
	{
		del_query(query);
		exit(0);
	}
	child_pid = pipex_error_try_fork();
	if (!child_pid)
		child(query);
	parent(query, child_pid);
	return (0);
}
