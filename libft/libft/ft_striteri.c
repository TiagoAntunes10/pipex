/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 14:49:13 by tialbert          #+#    #+#             */
/*   Updated: 2023/09/29 14:49:15 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		(*f)(i, &s[i]);
		i++;
	}
}

/*#include <stdio.h>
void	f(unsigned int n, char *s)
{
	(void) n;
	printf("%c", *s);
}

int main(void)
{
    char    *s;

    s = "SDFJNFN";
    ft_striteri(s, f);
}*/