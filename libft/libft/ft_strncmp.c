/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:36:54 by tialbert          #+#    #+#             */
/*   Updated: 2023/09/08 10:12:58 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strncmp(char const *s1, char const *s2, size_t n)
{
	unsigned int	i;

	i = 1;
	while (i <= n)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1 += 1;
		s2 += 1;
		i++;
	}
	return (0);
}

/*
#include <string.h>
int	main(void)
{
	char	*s1;
	char	*s2;
	unsigned int	n;

	s1 = "hellodsfsi";
	s2 = "hellodsfsi";
	n = 15;
	printf("%d\n", ft_strncmp(s1, s2, n));
	printf("%d\n", strncmp(s1, s2, n));
}*/
