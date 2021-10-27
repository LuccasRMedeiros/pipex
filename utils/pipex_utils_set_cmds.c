/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_set_cmds.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 17:07:13 by lrocigno          #+#    #+#             */
/*   Updated: 2021/10/27 11:54:14 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_utils.h"

/*
** Search for the PATH variable inside the envp.
*/

static char	*find_path_var(char **envp)
{
	int		p;
	char	*path;

	p = 0;
	while (envp[p])
	{
		path = ft_strnstr(envp[p], "PATH", 4);
		if (path)
			return (path);
		++p;
	}
	return (NULL);
}

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
		if (!access(try_path, F_OK))
		{
			ft_destroyer((void **)paths);
			return (try_path);
		}
		free(try_path);
		try_path = NULL;
		++path_i;
	}
	ft_destroyer((void **)paths);
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

void	pipex_utils_set_cmds(t_query *query, char **argv, char **envp)
{
	int		i;
	char	*path;

	i = 0;
	path = find_path_var(envp);
	while (i < query->cmdc)
	{
		query->list_argvs[i] = ft_split(argv[i], ' ');
		query->list_cmds[i] = chose_path(query->list_argvs[i][0], path);
		++i;
	}
	query->envp = envp;
}
