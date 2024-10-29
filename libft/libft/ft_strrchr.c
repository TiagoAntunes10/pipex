/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:40:50 by tialbert          #+#    #+#             */
/*   Updated: 2023/10/03 11:40:51 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char const *s, int c)
{
	char	*cs;

	cs = (char *) s;
	cs += ft_strlen(cs) - 1;
	while (*cs != '\0')
	{
		if (*cs == c)
			return (cs);
		else
			cs--;
	}
	if (*cs == c)
		return (cs);
	else
		return ("\0");
}

/*
#include <stdio.h>
#include <string.h>

int main(void)
{
    char    *s;
    char    c;

    s = "hfdb hnjnhdfb";
    c = 'n';
    printf("ft_strrchr: %s\n", ft_strrchr(s, c));
    printf("strrchr: %s\n", strrchr(s, c));
}*/
