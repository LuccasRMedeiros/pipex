/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_set_header.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 20:39:02 by lrocigno          #+#    #+#             */
/*   Updated: 2021/10/23 01:59:20 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_utils.h"

/*
** Call pipe to set the read and the write file descriptors.
**
** In case of an error occur, the program will silently exit with 0.
*/

t_header	*pipex_utils_set_header(char **envp)
{
	t_header	*header;

	ft_bzero(header, 1);
	if (pipe(header.fds) == -1)
	{
		del_header(&header);
		exit(0);
	}
	header.envp = envp;
	return (header);
}
