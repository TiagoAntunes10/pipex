/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 09:01:46 by tialbert          #+#    #+#             */
/*   Updated: 2024/02/01 10:48:24 by tialbert         ###   ########.fr       */
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
#include "./libft/ft_printf.h"

extern char	**environ;

char	*write_path(char *cmd, char **path);
void	free_array(char **array, char *path);
void	handle_errors(char **arr, int fd);
void	cmd_not_found(char *cmd);
void	check_outfile(char **argv, int argc);
char	**split_check(char *cmd, char **arr);
char	**get_path(char **environ);
// int		write_file(char **argv, int argc);
// int		write_one_cmd(char **argv, int argc);
