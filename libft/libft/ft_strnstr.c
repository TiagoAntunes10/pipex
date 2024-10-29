/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 21:39:34 by tialbert          #+#    #+#             */
/*   Updated: 2023/10/06 21:39:36 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

static int	find_str(char *big, char const *small, size_t len, size_t count);

char	*ft_strnstr(char const *big, char const *small, size_t len)
{
	int				i;
	unsigned int	j;
	char			*s;

	s = (char *) big;
	j = 0;
	if (*small == '\0')
		return (s);
	while (j < len)
	{
		i = 0;
		if (*small == *s)
			i = find_str(s, small, len, j);
		if (*(small + i) == '\0')
			return (s);
		else
			s++;
		j++;
	}
	return ("\0");
}

static int	find_str(char *big, char const *small, size_t len, size_t count)
{
	int	i;

	i = 0;
	while (*small == *big && *small != '\0' && count < len)
	{
		small += 1;
		big += 1;
		i++;
		count++;
	}
	return (i);
}

/*
#include <string.h>

int	main(void)
{
	char	*big;
	char	*small;
	unsigned int	i;

	i = 7;
	big = "teteste";
	small = "teste";
	printf("ft_strnstr: %s\n", ft_strnstr(big, small, i));
}*/
