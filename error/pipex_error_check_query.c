/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_error_check_query.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 00:18:37 by lrocigno          #+#    #+#             */
/*   Updated: 2021/10/27 14:36:53 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_error.h"

/*
** As the utils functions are not responsible for error management, when a
** invalid command is passed on the arguments, the query receive a NULL command
** and the program continue. This function verify if it was the case, if so,
** call access again with F_OK flag to allow it to set the errno properly, then
** cleanup everything, closes the file descriptors opened by pipe() and exit the
** program with 0.
*/

void	pipex_error_check_query(t_query *query)
{
	int	i;

	i = 0;
	while (i < query->cmdc)
	{
		if (!query->list_cmds[i])
		{
			access(query->list_argvs[i][0], X_OK);
			perror("Problem with commands");
			del_query(query);
			exit (0);
		}
		++i;
	}
}
