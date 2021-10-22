/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_parse_env.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 15:11:02 by lrocigno          #+#    #+#             */
/*   Updated: 2021/10/20 19:26:39 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_utils.h"

/*
** Get the PATH inside the envp and return a char **.
**
** In case of error it will exit silently with 0.
*/

char	**pipex_utils_parse_env(char **env)
{
	char **ret_env;

	ret_env = ft_split(env, ':');
	if (!ret_env)
		exit(0);
	return (ret_env);
}
