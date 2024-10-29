/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 14:53:56 by tialbert          #+#    #+#             */
/*   Updated: 2023/09/29 14:53:57 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;
	int				l;

	i = 0;
	l = ft_strlen(s);
	str = malloc(l);
	if (str == 0)
		return (NULL);
	while (s[i] != '\0')
	{
		str[i] = (*f)(i, s[i]);
		i++;
	}
	return (str);
}

/*
char	f(unsigned int n, char s)
{
	(void) n;
	return (s + 32);
}

#include <stdio.h>

int	main(void)
{
	char const	*s;

	s = "SHBFHFB";
	printf("%s\n", ft_strmapi(s, f));
}*/