/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_redir.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 20:45:01 by lrocigno          #+#    #+#             */
/*   Updated: 2021/10/21 22:59:15 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_utils.h"

/*
** Use dup2 to redirect one of the ends linked by pipe then close the old fd.
**
** In case of error exit silently with 0.
*/

void	pipex_utils_redir(int oldfd, int newfd)
{
	if (dup2(oldfd, newfd) < 0)
		exit(0);
	close(oldfd);
}
