/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limiter_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 21:20:30 by tialbert          #+#    #+#             */
/*   Updated: 2024/02/01 11:15:16 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	fork_func(char **argv, int argc, char **cmd_path);
static void	parent_func(int *fd, char **argv, int argc, char **cmd_path);
static void	child_func(int *fd, char **argv, char **cmd_path);

void	limiter(char **argv, int argc)
{
	char	**cmd_path;

	errno = 0;
	if (argc < 6)
	{
		perror("Not enough arguments!");
		errno = EIO;
		exit (errno);
	}
	cmd_path = get_path(environ);
	fork_func(argv, --argc, cmd_path);
}

static void	fork_func(char **argv, int argc, char **cmd_path)
{
	int	fd[2];
	int	id;

	if (pipe(fd) == -1)
		handle_errors(cmd_path, 0);
	id = fork();
	if (id == -1)
		handle_fd(fd, 1, cmd_path);
	else if (id == 0)
		child_func(fd, argv, cmd_path);
	else
		parent_func(fd, argv, argc, cmd_path);
}

static void	parent_func(int *fd, char **argv, int argc, char **cmd_path)
{
	char	*path;
	char	**cmd;
	int		status;

	close(fd[1]);
	fd[1] = open(argv[argc], O_WRONLY | O_CREAT | O_APPEND, 0777);
	if (fd[1] == -1)
		handle_errors(cmd_path, fd[0]);
	waitpid(-1, &status, WNOHANG);
	handle_fd(fd, 0, cmd_path);
	cmd = split_check(argv[argc - 1], cmd_path);
	if (cmd == NULL)
		exit(1);
	path = write_path(cmd[0], cmd_path);
	free_array(cmd_path, NULL);
	if (execve(path, cmd, environ) == -1)
	{
		if (errno == ENOENT || errno == EKEYEXPIRED)
			cmd_not_found(cmd[0]);
		else
			perror(strerror(errno));
		free_array(cmd, path);
		exit(127);
	}
}

int	get_input(char **cmd_path)
{
	int		fd[2];
	char	*line;

	if (pipe(fd) == -1)
		handle_errors(cmd_path, 0);
	line = get_next_line(0);
	while (ft_strncmp(line, "LIMITER", 7) != 0)
	{
		write(fd[1], line, ft_strlen(line));
		free(line);
		line = get_next_line(0);
	}
	free(line);
	close(fd[1]);
	return (fd[0]);
}

static void	child_func(int *fd, char **argv, char **cmd_path)
{
	char	*path;
	char	**cmd;

	close(fd[0]);
	fd[0] = get_input(cmd_path);
	handle_fd(fd, 0, cmd_path);
	cmd = split_check(argv[3], cmd_path);
	if (cmd == NULL)
		exit(1);
	path = write_path(cmd[0], cmd_path);
	free_array(cmd_path, NULL);
	if (execve(path, cmd, environ) == -1)
	{
		if (errno == ENOENT || errno == EKEYEXPIRED)
			cmd_not_found(cmd[0]);
		else
			perror(strerror(errno));
		free_array(cmd, path);
	}
}
