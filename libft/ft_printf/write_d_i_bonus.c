/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_d_i_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 08:18:19 by tialbert          #+#    #+#             */
/*   Updated: 2023/12/18 10:08:00 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	write_left_space(int long nb, unsigned int size, int count,
					long int size_precision)
{
	if (size <= size_precision)
		return (write_precision_nb(nb, size_precision, count));
	else if (size_precision == -1)
	{
		if (size <= (unsigned int)(nb_len(nb) + count))
		{
			ft_putnbr_fd(nb, 1);
			return (nb_len(nb) + count);
		}
		else
		{
			write_char(size - (nb_len(nb) + count), ' ');
			ft_putnbr_fd(nb, 1);
			return (size);
		}
	}
	else
	{
		if (nb < 0)
			write_char(size - (size_precision + count + 1), ' ');
		else
			write_char(size - (size_precision + count), ' ');
		write_precision_nb(nb, size_precision, count);
		return (size);
	}
}

int	write_left_nb(int long nb, unsigned int size, int count,
				long int size_precision)
{
	if (size <= size_precision)
		return (write_precision_nb(nb, size_precision, count));
	else if (size_precision == -1)
	{
		ft_putnbr_fd(nb, 1);
		if (size <= (unsigned int)(nb_len(nb) + count))
			return (nb_len(nb) + count);
		else
		{
			write_char(size - (nb_len(nb) + count), ' ');
			return (size);
		}
	}
	else
	{
		count = write_precision_nb(nb, size_precision, count);
		write_char(size - count, ' ');
		return (size);
	}
}

int	write_precision_nb(int long nb, unsigned int size, int count)
{
	unsigned int	len;

	if (size == 0 && nb == 0)
		return (count);
	if (nb < 0)
	{
		ft_putchar_fd('-', 1);
		nb *= -1;
		size++;
		count++;
	}
	len = nb_len(nb);
	if (size <= (unsigned int)(len + count))
	{
		write_nbr(nb, 1);
		return ((len + count));
	}
	else
	{
		write_char(size - (len + count), '0');
		write_nbr(nb, 1);
		return (size);
	}
}

int	write_zero_nb(int long nb, unsigned int size, int count,
				long int size_precision)
{
	if (size <= size_precision)
		return (write_precision_nb(nb, size_precision, count));
	else if (size_precision == -1)
	{
		if (size <= (unsigned int)(nb_len(nb) + count))
		{
			ft_putnbr_fd(nb, 1);
			return ((nb_len(nb) + count));
		}
		else
		{
			if (nb < 0)
			{
				ft_putchar_fd('-', 1);
				nb *= -1;
				count++;
			}
			write_char(size - (nb_len(nb) + count), '0');
			write_nbr(nb, 1);
			return (size);
		}
	}
	else
		return (write_left_space(nb, size, count, size_precision));
}
