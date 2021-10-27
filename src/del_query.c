/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_query.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 00:04:33 by lrocigno          #+#    #+#             */
/*   Updated: 2021/10/27 13:33:47 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
** Delete a t_query.
*/

void	del_query(t_query *del)
{
	int	i;

	i = 0;
	ft_destroyer((void **)del->list_cmds);
	while (i < del->cmdc - 1)
	{
		ft_destroyer((void **)del->list_argvs[i]);
		++i;
	}
	free(del->list_argvs);
	del->list_argvs = NULL;
	free(del);
	del = NULL;
}
