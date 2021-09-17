/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 15:36:13 by lrocigno          #+#    #+#             */
/*   Updated: 2021/09/17 20:19:45 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/* 
** Main function.
*/

int	main(void)
{
	char *arg = "ok bro";
	char *env;

	execve("echo", &arg, &env);
	return (0);
}
