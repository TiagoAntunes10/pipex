/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 09:45:01 by tialbert          #+#    #+#             */
/*   Updated: 2023/09/29 09:45:03 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_strlen_2(char const *str, char const *set, int end);
static int	set_cmp(char s, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		l;

	l = ft_strlen(s1);
	l = ft_strlen_2(s1, set, l - 1);
	str = malloc(l + 1);
	while (set_cmp(*s1, set) != 0)
		s1++;
	str = ft_substr(s1, 0, l);
	str[l] = '\0';
	return (str);
}

static int	ft_strlen_2(char const *str, char const *set, int end)
{
	int	l;

	l = 0;
	while (set_cmp(str[l], set) != 0 || set_cmp(str[end], set) != 0)
	{
		if (set_cmp(str[l], set) != 0)
			l++;
		if (set_cmp(str[end], set) != 0)
			end--;
	}
	end -= l - 1;
	return (end);
}

static int	set_cmp(char s, char const *set)
{
	while (*set != '\0')
	{
		if (s == *set)
			return (1);
		set++;
	}
	return (0);
}

/*
#include <stdio.h>

int main(void)
{
	char	*s1;
	char	*set;

	s1 = " ... .. . sdhj.d.s .hj.dhd. .. ..";
	set = ". ";
	printf("%s\n", ft_strtrim(s1, set));
}*/