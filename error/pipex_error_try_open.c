/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_error_try_open.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 20:31:59 by lrocigno          #+#    #+#             */
/*   Updated: 2021/10/27 23:45:45 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_error.h"

/*
** Try to open an file using the mode specified by the user, if it does not
** works, emit an error message, then exist the program.
**
** Return the opened file descriptor when the 
*/

int	pipex_error_try_open(char *pathname, int flags, mode_t mode)
{
	int	ret_fd;

	ret_fd = -1;
	if (mode)
		ret_fd = open(pathname, flags, mode);
	else
		ret_fd = open(pathname, flags);
	if (ret_fd < 0)
		perror(pathname);
	return (ret_fd);
}
