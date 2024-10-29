/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 09:53:31 by tialbert          #+#    #+#             */
/*   Updated: 2024/02/01 10:53:44 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	handle_errors(char **arr, int fd)
{
	if (arr != NULL)
		free_array(arr, NULL);
	if (fd > 0)
		close(fd);
	if (errno == 0)
		exit(12);
	perror(strerror(errno));
	exit(errno);
}

static char	*make_path(char *path, char *cmd)
{
	char	*path_cmd;

	path_cmd = malloc(ft_strlen(cmd) + ft_strlen(path) + 2);
	if (path_cmd == NULL)
		return (NULL);
	ft_bzero(path_cmd, ft_strlen(cmd) + ft_strlen(path) + 2);
	ft_strlcat(path_cmd, path, ft_strlen(path) + 1);
	ft_strlcat(path_cmd, "/", ft_strlen(path) + 2);
	ft_strlcat(path_cmd, cmd, ft_strlen(path) + ft_strlen(cmd) + 2);
	return (path_cmd);
}

char	*write_path(char *cmd, char **path)
{
	char	*path_cmd;

	if (access(cmd, F_OK) == -1)
	{
		while (*path != NULL)
		{
			path_cmd = make_path(*path, cmd);
			if (path_cmd == NULL)
				return (NULL);
			if (access(path_cmd, F_OK | X_OK) != -1)
				return (path_cmd);
			free(path_cmd);
			path++;
		}
		return (ft_substr(cmd, 0, ft_strlen(cmd)));
	}
	else
	{
		if (access(cmd, X_OK) == -1)
			handle_errors(path, 0);
		path_cmd = ft_substr(cmd, 0, ft_strlen(cmd));
	}
	return (path_cmd);
}

void	free_array(char **array, char *path)
{
	int		i;

	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
	if (path != NULL)
		free(path);
}

void	cmd_not_found(char *cmd)
{
	ft_printf("command not found: %s\n", cmd);
	errno = EKEYEXPIRED;
}

// int	write_file(char **argv, int argc)
// {
// 	int		fd[2];
// 	char	*line;

// 	fd[0] = open(argv[argc], O_WRONLY | O_CREAT, 0777);
// 	fd[1] = open(argv[1], O_RDONLY);
// 	if (fd[0] == -1 || fd[1] == -1)
// 	{
// 		perror(strerror(errno));
// 		return (0);
// 	}
// 	line = get_next_line(fd[1]);
// 	while (line != NULL)
// 	{
// 		write(fd[0], line, ft_strlen(line));
// 		free(line);
// 		line = get_next_line(fd[1]);
// 	}
// 	free(line);
// 	close(fd[0]);
// 	close(fd[1]);
// 	return (0);
// }

// int	write_one_cmd(char **argv, int argc)
// {
// 	int		fd[2];
// 	char	**cmd;

// 	fd[0] = open(argv[argc], O_WRONLY | O_CREAT, 0777);
// 	fd[1] = open(argv[1], O_RDONLY);
// 	if (fd[0] == -1 || fd[1] == -1)
// 	{
// 		perror(strerror(errno));
// 		return (0);
// 	}
// 	if (dup2(fd[0], 1) == -1 || dup2(fd[1], 0) == -1)
// 	{
// 		perror(strerror(errno));
// 		return (0);
// 	}
// 	close(fd[0]);
// 	close(fd[1]);
// 	cmd = sep_args(argv[argc - 1], "/usr/bin/");
// 	if (execve(cmd[0], cmd, NULL) == -1)
// 	{
// 		perror(strerror(errno));
// 		return (0);
// 	}
// 	return (0);
// }
