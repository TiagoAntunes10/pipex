/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 16:47:40 by tialbert          #+#    #+#             */
/*   Updated: 2023/08/28 12:32:12 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char const *str)
{
	int	l;

	l = 0;
	while (*str != '\0')
	{
		++l;
		++str;
	}
	return (l);
}

/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	char	*str;

	str = "abcd";
	printf("%d\n", ft_strlen(str));
	printf("%ld\n", strlen(str));
}*/
