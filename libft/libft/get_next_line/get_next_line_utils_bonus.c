/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 21:06:37 by tialbert          #+#    #+#             */
/*   Updated: 2023/12/18 09:46:11 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	read_file(char *buffer, char **char_lake, int fd)
{
	char	*temp;
	int		check;

	check = 1;
	while (gnl_strchr(*char_lake, '\n') == NULL && check > 0)
	{
		gnl_bzero(buffer, BUFFER_SIZE + 1);
		check = read(fd, buffer, BUFFER_SIZE);
		if (check == -1 || buffer == NULL)
		{
			free(*char_lake);
			*char_lake = NULL;
			return (check);
		}
		if (check == 0)
			return (check);
		temp = gnl_strjoin(*char_lake, buffer);
		free(*char_lake);
		*char_lake = temp;
	}
	return (check);
}

void	gnl_bzero(void *s, size_t n)
{
	unsigned int	i;
	char			*cs;

	i = 0;
	cs = (char *) s;
	while (i < n)
	{
		cs[i] = 0;
		i++;
	}
}

char	*gnl_strjoin(char const *s1, char const *s2)
{
	int			j;
	char		*str;

	j = 0;
	str = malloc(gnl_strlen(s1) + gnl_strlen(s2) + 1);
	if (str == 0)
		return (NULL);
	if (s1 != NULL)
	{
		while (*s1 != '\0')
		{
			str[j] = *s1;
			s1++;
			j++;
		}
	}
	while (*s2 != '\0')
	{
		str[j] = *s2;
		s2++;
		j++;
	}
	str[j] = '\0';
	return (str);
}

size_t	gnl_strlen(char const *str)
{
	int	l;

	if (str == NULL)
		return (0);
	l = 0;
	while (*str != '\0')
	{
		++l;
		++str;
	}
	return (l);
}

char	*gnl_strchr(char const *s, int c)
{
	char	*cs;

	cs = (char *) s;
	if (cs == NULL)
		return (NULL);
	while (*cs != '\0')
	{
		if (*cs == (unsigned char) c)
			return (cs);
		else
			cs++;
	}
	if (*cs == (unsigned char) c)
		return (cs);
	else
		return (NULL);
}
