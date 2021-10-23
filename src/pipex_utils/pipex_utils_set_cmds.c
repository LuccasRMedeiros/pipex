/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_set_cmds.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 17:07:13 by lrocigno          #+#    #+#             */
/*   Updated: 2021/10/22 23:34:51 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_utils.h"

/*
** Try to access the command through every path in PATH environment variable.
** The one that works is returned. Case none of them works, returns NULL, is
** responsability of the caller of set_cmds to deal with the error.
*/

static char	*chose_path(char *cmd, char *path)
{
	char	**paths;
	int		path_i;
	char	*try_path;

	paths = ft_split(path, ':');
	path_i = 0;
	while (paths[path_i])
	{
		try_path = ft_strjoin(paths[path_i], "/");
		try_path = ft_reallocncat(try_path, cmd);
		if (!access(try_path, X_OK))
			return (try_path);
		free(try_path);
		try_path = NULL;
		++path_i;
	}
	return (NULL);
}

/*
** Parse the commands and return a NULL terminated list.
**
** Is assumed that the argc less two is the total amount of commands that will
** be in the pipe as the first argument and the last one are files. Wrong
** arguments must be catch before the call of set_cmds.
**
** It uses malloc to set the total size of the returned structure, case this
** operation fails, it will exit silently with zero.
**
** NOTE: 
*/

t_cmd	*pipex_utils_set_cmds(int argc, char **argv, char *path)
{
	int		hm;
	t_cmd	*cmds;
	int		i;

	hm = argc - 2;
	cmds = malloc(sizeof(*cmds) * hm + 1);
	if (!cmds)
		exit(0);
	i = 0;
	while (i < hm)
	{
		cmds[i]->argv = ft_split(argv[i + 1], ' ');
		cmds[i]->cmd = chose_path(cmds[i].argv[0], path);
		++i;
	}
	cmds[i] = NULL;
	return (cmds);
}
