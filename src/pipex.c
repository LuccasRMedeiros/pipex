/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 15:36:13 by lrocigno          #+#    #+#             */
/*   Updated: 2021/09/18 11:17:47 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "pipex_error/pipex_error.h"

/* 
** Main function.
*/

int	main(int argc, char **argv)
{
	char	**fargv;
	char	**env;

	do_nothing(argc, *argv);
	fargv = ft_split("testingtester ", ' ');
	execve("echo", fargv, env);
	ft_destroyer((void **)fargv);
	return (0);
}
