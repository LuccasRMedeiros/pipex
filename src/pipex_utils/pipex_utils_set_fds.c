/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_set_fds.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 20:39:02 by lrocigno          #+#    #+#             */
/*   Updated: 2021/10/22 00:52:20 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_utils.h"

/*
** Call pipe to set the read and the write file descriptors.
**
** In case of an error occur, the program will silently exit with 0.
*/

int	*pipex_utils_set_header(void)
{
	t_header	*header;

	header = new_header();
	if (pipe(header.fds) == -1)
	{
		del_header(&header);
		exit(0);
	}
	header.envp
	return (ret);
}
