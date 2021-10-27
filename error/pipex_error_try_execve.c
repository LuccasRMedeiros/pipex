/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_error_try_execve.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 19:13:09 by lrocigno          #+#    #+#             */
/*   Updated: 2021/10/27 16:09:57 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_error.h"

/*
** Try to execute a command, in case some error happens use perror to sinalize,
** then exit the program with 0.
*/

int	pipex_error_try_execve(t_query *query, int p)
{
	if (execve(query->list_cmds[p], query->list_argvs[p], query->envp) < 0)
	{
		perror("Problem when attempt to execute new task");
		del_query(query);
		exit(-1);
	}
	return (1);
}
