/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 20:33:16 by lrocigno          #+#    #+#             */
/*   Updated: 2021/10/26 23:42:59 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Pipex utils groups functions that help the pipex to work as expected.
*/

#ifndef PIPEX_UTILS_H
# define PIPEX_UTILS_H

# include <pipex.h>

char	**pipex_utils_parse_cmd(const char *cmd, const char *pathname);
void	pipex_utils_set_cmds(t_query *query, char **argv, char **envp);
void	pipex_utils_redir(int oldfd, int newfd);

#endif
