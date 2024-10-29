/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:47:49 by tialbert          #+#    #+#             */
/*   Updated: 2024/02/01 10:46:17 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	write_char(unsigned int size, char c)
{
	unsigned int	i;

	i = 0;
	while (i < size)
	{
		ft_putchar_fd(c, 2);
		i++;
	}
}

void	write_nbr(unsigned long int nb, int fd)
{
	int	div;
	int	mod;

	div = nb / 10;
	mod = nb % 10;
	if (div == 0)
	{
		mod += 48;
		write(fd, &mod, 1);
		return ;
	}
	else
		write_nbr(div, fd);
	mod += 48;
	write(fd, &mod, 1);
	return ;
}

long int	check_precision(char *format)
{
	while (*format != '\0')
	{
		if (*format == '.')
			return (ft_atoi(format + 1));
		format++;
	}
	return (-1);
}

int	nb_len_positive(int long nb)
{
	int	l;

	l = 0;
	if (nb < 0)
		nb *= -1;
	if (nb / 10 == 0)
		return (l + 1);
	l += 1;
	l += nb_len(nb / 10);
	return (l);
}

int	write_nil_left(unsigned int size)
{
	ft_putstr_fd("(nil)", 1);
	write_char((size - 5), ' ');
	return (size);
}
