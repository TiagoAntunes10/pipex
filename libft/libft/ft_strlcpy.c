/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 18:02:15 by tialbert          #+#    #+#             */
/*   Updated: 2024/01/25 15:18:44 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

static int	check_slash(const char *c)
{
	if (*(c - 1) == '\\' && *c == '\\'
		&& (*(c + 1) == '\'' || *(c + 1) == '"'))
		return (1);
	return (0);
}

unsigned int	ft_strlcpy(char *dest, char const *src, size_t size)
{
	unsigned int	i;

	i = 1;
	while (*src != '\0')
	{
		if (*src == '\\' && i > 1)
		{
			if (check_slash(src) == 1)
			{
				src += 2;
				size -= 2;
			}
		}
		if (i < size)
		{
			*dest = *src;
			dest += 1;
		}
		src += 1;
		i++;
		if ((*src == '\'' || *src == '"') && i == size - 1)
			src++;
	}
	*dest = '\0';
	return ((i - 1));
}

/*int	main(void)
{
	char	*src;
	char	dest[20];
	int	i;

	src = "hello ahsdhv";
	i = ft_strlcpy(dest, src, 4);
	printf ("%s, %d\n", dest, i);
}*/
