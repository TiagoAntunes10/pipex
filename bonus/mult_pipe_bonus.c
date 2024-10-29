/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mult_pipe_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 21:20:36 by tialbert          #+#    #+#             */
/*   Updated: 2024/02/04 10:02:12 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	fork_func(char **argv, int argc, char **cmd_path);
static void	parent_func(int *fd, char **argv, int argc, char **cmd_path);
void		mid_func(int *fd, char **argv, int argc, char **cmd_path);
static void	end_func(int *fd, char **argv, char **cmd_path);

void	multi(char **argv, int argc)
{
	int		fd;
	char	**cmd_path;

	errno = 0;
	check_outfile(argv, --argc);
	if (access(argv[1], F_OK | R_OK) == -1)
	{
		fd = open(argv[argc], O_WRONLY | O_CREAT, 0777);
		if (fd == -1)
			handle_errors(NULL, 0);
		write(fd, "0\n", 2);
		perror(strerror(errno));
		exit(0);
	}
	cmd_path = get_path(environ);
	fork_func(argv, argc, cmd_path);
}

static void	fork_func(char **argv, int argc, char **cmd_path)
{
	int	fd[2];
	int	id;

	if (pipe(fd) == -1)
		handle_errors(NULL, 0);
	id = fork();
	if (id == -1)
		handle_fd(fd, 1, cmd_path);
	else if (id == 0)
		mid_func(fd, argv, --argc, cmd_path);
	else
		parent_func(fd, argv, argc, cmd_path);
}

static void	parent_func(int *fd, char **argv, int argc, char **cmd_path)
{
	char	*path;
	char	**cmd;
	int		status;

	close(fd[1]);
	fd[1] = open(argv[argc], O_WRONLY | O_CREAT, 0777);
	if (fd[1] == -1)
		handle_errors(cmd_path, fd[0]);
	waitpid(-1, &status, WNOHANG);
	handle_fd(fd, 0, cmd_path);
	cmd = split_check(argv[argc - 1], cmd_path);
	if (cmd == NULL)
		exit(12);
	path = write_path(cmd[0], cmd_path);
	free_array(cmd_path, NULL);
	if (execve(path, cmd, environ) == -1)
	{
		if (errno == ENOENT || errno == EKEYEXPIRED)
			cmd_not_found(cmd[0]);
		else
			perror(strerror(errno));
		free_array(cmd, path);
		exit(errno);
	}
}

void	mid_func(int *fd, char **argv, int argc, char **cmd_path)
{
	char	*path;
	char	**cmd;

	close(fd[0]);
	if (argc == 3)
		end_func(fd, argv, cmd_path);
	fd[0] = mid_fork(argv, argc - 1, cmd_path);
	handle_fd(fd, 0, cmd_path);
	cmd = split_check(argv[argc - 1], cmd_path);
	if (cmd == NULL)
		exit(12);
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

static void	end_func(int *fd, char **argv, char **cmd_path)
{
	char	*path;
	char	**cmd;

	fd[0] = open(argv[1], O_RDONLY);
	if (fd[0] == -1)
		handle_errors(cmd_path, fd[1]);
	handle_fd(fd, 0, cmd_path);
	cmd = split_check(argv[2], cmd_path);
	if (cmd == NULL)
		exit(12);
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
