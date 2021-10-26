/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_error_try_execve.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 19:13:09 by lrocigno          #+#    #+#             */
/*   Updated: 2021/10/25 20:26:56 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_error.h"

/*
** Try to execute a command, in case some error happens use perror to sinalize,
** then exit the program with 0.
*/

void	pipex_error_try_execve(t_query *query, int p)
{
	if (execve(query->cmds[p].cmd, query->cmds[p].argv, query->header.envp) < 0)
	{
		perror("Pipex error:");
		exit(2);
	}
}
