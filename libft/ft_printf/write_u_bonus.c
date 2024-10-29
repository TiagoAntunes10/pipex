/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_u_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 14:19:44 by tialbert          #+#    #+#             */
/*   Updated: 2023/12/18 10:10:49 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	write_precision_unsigned(unsigned long int nb, unsigned int size,
				int count);

static int	write_space_unsigned(unsigned int long nb, unsigned int size,
				int count, long int size_precision)
{
	if (size <= size_precision)
		return (write_precision_unsigned(nb, size_precision, count));
	else if (size_precision == -1)
	{
		if (size <= (unsigned int)(nb_len(nb) + count))
		{
			write_nbr(nb, 1);
			return (nb_len(nb) + count);
		}
		else
		{
			write_char(size - (nb_len(nb) + count), ' ');
			write_nbr(nb, 1);
			return (size);
		}
	}
	else
	{
		write_char(size - (size_precision + count), ' ');
		write_precision_unsigned(nb, size_precision, count);
		return (size);
	}
}

static int	write_left_unsigned(unsigned long int nb, unsigned int size,
							int count, long int size_precision)
{
	if (size <= size_precision)
		return (write_precision_unsigned(nb, size_precision, count));
	else if (size_precision == -1)
	{
		write_nbr(nb, 1);
		if (size <= (unsigned int)(nb_len(nb) + count))
			return ((nb_len(nb) + count));
		else
		{
			write_char(size - (nb_len(nb) + count), ' ');
			return (size);
		}
	}
	else
	{
		count = write_precision_unsigned(nb, size_precision, count);
		write_char(size - count, ' ');
		return (size);
	}
}

static int	write_precision_unsigned(unsigned long int nb, unsigned int size,
								int count)
{
	if (size == 0 && nb == 0)
		return (count);
	else if (size <= (unsigned int)(nb_len(nb) + count))
	{
		write_nbr(nb, 1);
		return ((nb_len(nb) + count));
	}
	else
	{
		write_char(size - (nb_len(nb) + count), '0');
		write_nbr(nb, 1);
		return (size);
	}
}

static int	write_zero_unsigned(unsigned long int nb, unsigned int size,
								int count, long int size_precision)
{
	if (size <= size_precision)
		return (write_precision_unsigned(nb, size_precision, count));
	else if (size_precision == -1)
	{
		if (size <= (unsigned int)(nb_len(nb) + count))
		{
			write_nbr(nb, 1);
			return ((nb_len(nb) + count));
		}
		else
		{
			write_char(size - (nb_len(nb) + count), '0');
			write_nbr(nb, 1);
			return (size);
		}
	}
	else
		return (write_left_space(nb, size, count, size_precision));
}

int	write_unsigned_bonus(unsigned long int nb, int count, char *format,
						long int size_precision)
{
	unsigned int	size;

	if (ft_isdigit(*format) > 0 && *format != '0')
	{
		size = ft_atoi(format);
		free(format);
		if (size_precision == 0 && nb != 0)
			return (write_space_unsigned(nb, (size - nb_len(nb)),
					count, size_precision));
		return (write_space_unsigned(nb, size, count, size_precision));
	}
	if (*format == '-')
	{
		size = ft_atoi(format + skip_minus(format));
		count += write_left_unsigned(nb, size, count, size_precision);
	}
	else
		size = ft_atoi(format + 1);
	if (*format == '.')
		count += write_precision_unsigned(nb, size, count);
	else if (*format == '0')
		count += write_zero_unsigned(nb, size, count, size_precision);
	free(format);
	return (count);
}
