/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:26:24 by tialbert          #+#    #+#             */
/*   Updated: 2023/12/18 10:05:32 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	write_left_spaces(int c, char *format);

int	write_c(va_list valst, int count, char *format)
{
	unsigned int	size;

	if (*format == '-' || *format == '.')
	{
		if (*format == '-')
			size = ft_atoi(format + skip_minus(format));
		else
			size = ft_atoi(format + 1);
		free(format);
		ft_putchar_fd(va_arg(valst, int), 1);
		if (size > 0)
		{
			write_char(size - 1, ' ');
			return (count + size - 1);
		}
		return (count++);
	}
	else if (ft_isdigit(*format) > 0)
		return (count + write_left_spaces(va_arg(valst, int), format));
	else if (*format == 0)
	{
		ft_putchar_fd(va_arg(valst, int), 1);
		return (count++);
	}
	return (count);
}

static int	write_left_spaces(int c, char *format)
{
	unsigned int	size;

	size = ft_atoi(format);
	free(format);
	if (size > 1)
	{
		write_char(size - 1, ' ');
		ft_putchar_fd(c, 1);
		return (size);
	}
	else
	{
		ft_putchar_fd(c, 1);
		return (1);
	}
}
