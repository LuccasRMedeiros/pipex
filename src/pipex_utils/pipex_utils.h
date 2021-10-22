/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 20:33:16 by lrocigno          #+#    #+#             */
/*   Updated: 2021/10/22 00:52:20 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Pipex utils groups functions that help the pipex to work as expected.
*/

#ifndef PIPEX_UTILS_H
# define PIPEX_UTILS_H

# include "../pipex/pipex.h"

# include <libft.h>
# include <errno.h>

char	**pipex_utils_parse_cmd(const char *cmd, const char *pathname);
int		*pipex_utils_set_fds(void);
void	pipex_utils_redir(int oldfd, int newfd);

#endif
