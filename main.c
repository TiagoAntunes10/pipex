/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 09:02:10 by tialbert          #+#    #+#             */
/*   Updated: 2024/02/01 10:48:47 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	fork_func(char **argv, int argc, char **cmd_path);
static void	parent_func(int *fd, char **argv, int argc, char **cmd_path);
static void	child_func(int *fd, char **argv, char **cmd_path);

int	main(int argc, char **argv)
{
	int		fd;
	char	**cmd_path;

	errno = 0;
	if (argc < 5)
	{
		perror("Not enough arguments!");
		errno = EIO;
		exit (errno);
	}
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
	return (fork_func(argv, argc, cmd_path));
}

static void	handle_fd(int *fd, int mode, char **cmd_path)
{
	if (mode == 0)
	{
		if (dup2(fd[1], 1) == -1 || dup2(fd[0], 0) == -1)
		{
			close(fd[0]);
			close(fd[1]);
			handle_errors(cmd_path, 0);
		}
	}
	else
	{
		close(fd[0]);
		close(fd[1]);
		handle_errors(cmd_path, 0);
	}
}

static int	fork_func(char **argv, int argc, char **cmd_path)
{
	int	fd[2];
	int	id;

	if (pipe(fd) == -1)
		handle_errors(NULL, 0);
	id = fork();
	if (id == -1)
	{
		handle_fd(fd, 1, cmd_path);
		handle_errors(NULL, 0);
	}
	else if (id == 0)
		child_func(fd, argv, cmd_path);
	else
		parent_func(fd, argv, argc, cmd_path);
	return (0);
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
		handle_errors(cmd_path, 0);
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

static void	child_func(int *fd, char **argv, char **cmd_path)
{
	char	*path;
	char	**cmd;

	close(fd[0]);
	fd[0] = open(argv[1], O_RDONLY);
	if (fd[0] == -1)
		handle_errors(cmd_path, fd[1]);
	handle_fd(fd, 0, cmd_path);
	cmd = split_check(argv[2], cmd_path);
	if (cmd == NULL)
		handle_errors(cmd_path, 0);
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
