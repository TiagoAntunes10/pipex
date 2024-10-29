/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 09:07:16 by tialbert          #+#    #+#             */
/*   Updated: 2023/09/11 17:44:17 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(char const *src)
{
	unsigned int		l;
	char				*str;

	l = ft_strlen(src);
	str = malloc (l);
	ft_strlcpy(str, src, l + 1);
	return (str);
}

/*
#include <stdio.h>
#include <string.h>
int main(void)
{
	char	*src;

	src = "Boas dfjb fhbb";
	printf("ft_strdup: %s\n", ft_strdup(src));
	printf("strdup: %s\n", strdup(src));
}*/
