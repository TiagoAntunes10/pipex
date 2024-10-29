/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:42:15 by tialbert          #+#    #+#             */
/*   Updated: 2023/10/03 11:42:16 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		return (c + 32);
	else
		return (c);
}

/*
#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char    c;

    c = 'G';
    printf("ft_tolower: %c\n", ft_tolower(c));
    printf("toulower: %c\n", tolower(c));
}*/