/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_set_cmds.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 17:07:13 by lrocigno          #+#    #+#             */
/*   Updated: 2021/10/28 11:21:46 by lrocigno         ###   ########.fr       */
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
**
** When the command does not exist (access() don't find the command with the
** paths) it return aux_cmd. aux_cmd is a duplication of cmd, and it exist for
** to alloc memory for this string, allowing the program to delete it properly
** in the unavoidable error.
*/

static char	*chose_path(char *cmd, char *path)
{
	char	**paths;
	int		path_i;
	char	*aux_cmd;
	char	*try_path;

	paths = ft_split(path, ':');
	path_i = 0;
	aux_cmd = ft_strdup(cmd);
	while (paths[path_i])
	{
		try_path = ft_strjoin(paths[path_i], "/");
		try_path = ft_reallocncat(try_path, cmd);
		if (!access(try_path, F_OK))
		{
			free(aux_cmd);
			aux_cmd = NULL;
			ft_destroyer((void **)paths);
			return (try_path);
		}
		free(try_path);
		try_path = NULL;
		++path_i;
	}
	ft_destroyer((void **)paths);
	return (aux_cmd);
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
