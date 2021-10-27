/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_query.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 00:01:37 by lrocigno          #+#    #+#             */
/*   Updated: 2021/10/27 11:38:08 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
** Initialize the list_argvs.
*/

static char	***init_list_argvs(int cmdc)
{
	int		i;
	char	***list_argvs;

	i = 0;
	list_argvs = malloc(sizeof(char ***) * (cmdc + 1));
	if (!list_argvs)
		return (NULL);
	while (i <= cmdc)
	{
		//list_argvs[i][0] = NULL;
		list_argvs[i] = NULL;
		++i;
	}
	return (list_argvs);
}

/*
** Initialize the list_cmds.
*/

static char	**init_list_cmds(int cmdc)
{
	int		i;
	char	**list_cmds;

	i = 0;
	list_cmds = malloc(sizeof(char **) * (cmdc + 1));
	if (!list_cmds)
		return (NULL);
	while (i <= cmdc)
	{
		list_cmds[i] = NULL;
		++i;
	}
	return (list_cmds);
}

/*
** Create a new t_query instance.
*/

t_query	*new_query(int cmdc)
{
	t_query	*new;

	new = malloc(sizeof(*new));
	new->cmdc = cmdc;
	if (pipe(new->fds) < 0)
		return (NULL);
	new->list_cmds = init_list_cmds(cmdc);
	if (new->list_cmds == NULL)
		return (NULL);
	new->list_argvs = init_list_argvs(cmdc);
	if (new->list_argvs == NULL)
	{
		free(new->list_cmds);
		return (NULL);
	}
	return (new);
}
