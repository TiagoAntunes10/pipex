/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:42:35 by tialbert          #+#    #+#             */
/*   Updated: 2023/10/03 11:42:36 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		return (c - 32);
	else
		return (c);
}

/*
#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char    c;

    c = 'g';
    printf("ft_toupper: %c\n", ft_toupper(c));
    printf("toupper: %c\n", toupper(c));
}*/