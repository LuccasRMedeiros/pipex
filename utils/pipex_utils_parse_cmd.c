/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_parse_cmd.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 11:19:46 by lrocigno          #+#    #+#             */
/*   Updated: 2021/10/20 19:26:39 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_utils.h"

/*
** Create a list of arguments to for the command.
**
** The argument const char *cmd is a string containing the entire command (cmd
** arg), and the const char *pathname refers to the infile/outfile.
**
** Upon a successful excecution it return a char **cmd_argv in which the first
** element is the name of the command been called, the subsequents are the
** arguments passed to it and the last one is NULL. In case of error, the
** program will exit silently with 0.
*/

char	**pipex_utils_parse_cmd(const char *cmd, const char *pathname)
{
	char	*full_line;
	char	**ret_argv;

	full_line = ft_strcomb(3, cmd, " ", pathname);
	ret_argv = ft_split(full_line, ' ');
	free(full_line);
	full_line = NULL;
	if (ret_argv == NULL)
		exit (0);
	return (ret_argv);
}
