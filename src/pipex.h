/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 19:27:59 by lrocigno          #+#    #+#             */
/*   Updated: 2021/10/26 23:41:07 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** This is the base header for all the program. Must be included in all the
** submodules, but never in the main function.
*/

#ifndef PIPEX_H
# define PIPEX_H

# include <libft.h>

typedef struct	s_query
{
	int		cmdc;
	int		fds[2];
	int		fd_in;
	int		fd_out;
	char	**envp;
	char	**list_cmds;
	char	***list_argvs;
}	t_query;

t_query		*new_query(int cmdc);
void		del_query(t_query *del);

#endif
