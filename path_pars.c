/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_pars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:13:22 by tialbert          #+#    #+#             */
/*   Updated: 2024/01/23 12:13:25 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_path(char **environ)
{
	char	**path;
	char	*temp;
	int		i;

	i = 0;
	path = NULL;
	while (environ[i] != NULL)
	{
		if (ft_strncmp(environ[i], "PATH", 4) == 0)
		{
			temp = ft_substr(environ[i], 5, ft_strlen(environ[i] + 5));
			path = ft_split(temp, ':');
			free(temp);
			break ;
		}
		i++;
	}
	return (path);
}
