/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:37:55 by tialbert          #+#    #+#             */
/*   Updated: 2024/02/01 11:14:08 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _GNU_SOURCE
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include "../libft/ft_printf.h"

extern char	**environ;

void	handle_fd(int *fd, int mode, char **cmd_path);
void	cmd_not_found(char *cmd);
void	multi(char **argv, int argc);
void	mid_func(int *fd, char **argv, int argc, char **cmd_path);
int		mid_fork(char **argv, int argc, char **cmd_path);
void	limiter(char **argv, int argc);
char	*write_path(char *cmd, char **path);
void	free_array(char **array, char *path);
void	handle_errors(char **arr, int fd);
void	check_outfile(char **argv, int argc);
char	**split_check(char *cmd, char **arr);
char	**get_path(char **environ);
// int		write_file(char **argv, int argc);
// int		write_one_cmd(char **argv, int argc);
