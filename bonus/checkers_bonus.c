/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:35:03 by tialbert          #+#    #+#             */
/*   Updated: 2024/02/01 11:14:11 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	check_outfile(char **argv, int argc)
{
	if (access(argv[argc], F_OK) == 0)
	{
		if (unlink(argv[argc]) == -1)
		{
			perror(strerror(errno));
			exit(1);
		}
	}
}

char	**split_check(char *cmd, char **arr)
{
	char	**pars;

	if (access(cmd, F_OK) == -1)
		pars = ft_split(cmd, ' ');
	else
	{
		if (access(cmd, X_OK) == -1)
			handle_errors(arr, 0);
		pars = malloc(sizeof(char *) * 2);
		*pars = ft_substr(cmd, 0, ft_strlen(cmd));
		*(pars + 1) = NULL;
	}
	return (pars);
}
