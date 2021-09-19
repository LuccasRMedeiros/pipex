/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_error_do_nothing.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 11:00:33 by lrocigno          #+#    #+#             */
/*   Updated: 2021/09/18 11:06:16 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_error.h"

/*
** Receive an indefinit number of arguments and do nothing, acting as a
** placeholder.
** The need for variadic, is to avoid warnings and grant compilation during
** development fase. This function is not meant to be kept in the code when
** released.
*/

void	do_nothing(int n_args, ...)
{
	va_list	keeper;

	va_start(keeper, n_args);
	va_end(keeper);
}
