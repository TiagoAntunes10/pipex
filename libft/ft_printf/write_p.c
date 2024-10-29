/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:26:39 by tialbert          #+#    #+#             */
/*   Updated: 2023/12/18 10:08:29 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	write_left_spaces(unsigned long long ptr, char *format);
static int	write_left_ptr(unsigned long long ptr, char *format);
static int	write_nil(char *format);

int	write_p(va_list valst, int count, char *format)
{
	unsigned long long	ptr;

	ptr = va_arg(valst, unsigned long long);
	if (ptr == 0)
		return (count + write_nil(format));
	else if (*format == '-')
		return (count + write_left_ptr(ptr, format));
	else if (ft_isdigit(*format) > 0)
		return (count + write_left_spaces(ptr, format));
	else if (*format == 0)
	{
		count += write_ptr(ptr, "0123456789abcdef", 16);
		return (count);
	}
	return (count);
}

int	len_ptr(unsigned long long ptr)
{
	int		count;

	count = 1;
	if ((ptr / 16) == 0)
		return (3);
	count += len_ptr(ptr / 16);
	return (count);
}

static int	write_left_spaces(unsigned long long ptr, char *format)
{
	unsigned int	len;
	unsigned int	size;

	size = ft_atoi(format);
	free(format);
	len = len_ptr(ptr);
	if (size <= (unsigned int) len)
	{
		write_ptr(ptr, "0123456789abcdef", 16);
		return (len);
	}
	else
	{
		write_char(size - len, ' ');
		write_ptr(ptr, "0123456789abcdef", 16);
		return (size);
	}
}

static int	write_left_ptr(unsigned long long ptr, char *format)
{
	unsigned int	size;
	unsigned int	count2;

	count2 = write_ptr(ptr, "0123456789abcdef", 16);
	size = ft_atoi(format + skip_minus(format));
	free(format);
	if ((count2) >= size)
		return (count2);
	else
	{
		write_char((size - count2), ' ');
		return (size);
	}
}

static int	write_nil(char *format)
{
	unsigned int	size;

	if (*format == '-')
	{
		size = ft_atoi(format + 1);
		free(format);
		if (size > 5)
			return (write_nil_left(size));
	}
	else if (ft_isdigit(*format) > 0)
	{
		size = ft_atoi(format);
		free(format);
		if (size > 5)
		{
			write_char((size - 5), ' ');
			ft_putstr_fd("(nil)", 1);
			return (size);
		}
	}
	ft_putstr_fd("(nil)", 1);
	return (5);
}
