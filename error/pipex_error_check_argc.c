/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_error_check_argc.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 17:54:06 by lrocigno          #+#    #+#             */
/*   Updated: 2021/10/27 18:08:28 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_error.h"

/*
** Check if the argc is equal to 5 what means that were informed two files and
** two commands.
**
** Case argc is different of 5, print a error messsage, before to exit with
** zero.
*/

void	pipex_error_check_argc(int argc)
{
	if (argc != 5)
	{
		ft_fprintf(2, "Please inform 'file cmd cmd file'\n");
		exit(0);
	}
}
