/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 15:36:13 by lrocigno          #+#    #+#             */
/*   Updated: 2021/10/03 18:59:22 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/* 
** Main function.
*/

int	main(int argc, char **argv, char **env)
{
	char	*new_argv[3];

	new_argv[0] = argv[2];
	new_argv[1] = argv[0];
	new_argv[2] = NULL;
	execve(argv[1], new_argv, env);
	return (argc - argc);
}
