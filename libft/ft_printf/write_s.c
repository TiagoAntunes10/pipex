/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:26:45 by tialbert          #+#    #+#             */
/*   Updated: 2024/02/01 10:45:41 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	write_left_spaces(char *str, unsigned int size);
static char	*write_precision_str(char *str, char *format);
static int	flag_condition(char *str, char *format);

int	write_s(va_list valst, int count, char *format)
{
	char			*str;
	unsigned int	len;

	str = va_arg(valst, char *);
	if (str == 0)
		str = "(null)";
	str = write_precision_str(str, format);
	if (*format == '-' || *format == ' ' || ft_isdigit(*format) > 0)
		return (count + flag_condition(str, format));
	else if (*format == 0 || *format == '.')
	{
		if (*format != 0)
			free(format);
		len = ft_strlen(str);
		ft_putstr_fd(str, 2);
		free(str);
		return (count + len);
	}
	return (count);
}

static int	write_left_spaces(char *str, unsigned int size)
{
	unsigned int	len;

	len = ft_strlen(str);
	if (*str == '\0')
	{
		write_char(size, ' ');
		free(str);
		return (size);
	}
	if (size <= (unsigned int) len)
	{
		ft_putstr_fd(str, 2);
		free(str);
		return (len);
	}
	else
	{
		write_char(size - len, ' ');
		ft_putstr_fd(str, 2);
		free(str);
		return (size);
	}
}

static int	write_left_str(char *str, unsigned int size)
{
	unsigned int	len;

	len = ft_strlen(str);
	ft_putstr_fd(str, 2);
	free(str);
	if (size <= (unsigned int) len)
		return (len);
	else
	{
		write_char(size - len, ' ');
		return (size);
	}
}

static char	*write_precision_str(char *str, char *format)
{
	long int	size;

	size = check_precision(format);
	if (ft_strncmp(str, "(null)", 6) == 0 && size >= 6)
		return (ft_substr(str, 0, 6));
	else if (ft_strncmp(str, "(null)", 6) == 0 && size > 0)
		return (malloc(1));
	if (size == -1 || size > (unsigned int) ft_strlen(str))
		return (ft_substr(str, 0, ft_strlen(str)));
	else if (size <= (unsigned int) ft_strlen(str))
		return (ft_substr(str, 0, size));
	return (ft_substr(str, 0, ft_strlen(str)));
}

static int	flag_condition(char *str, char *format)
{
	unsigned int	size;

	if (*format == '-' || *format == ' ')
	{
		if (*format == '-')
			size = ft_atoi(format + skip_minus(format));
		else
			size = ft_atoi(format + 1);
		free(format);
		return (write_left_str(str, size));
	}
	else if (ft_isdigit(*format) > 0)
	{
		size = ft_atoi(format);
		free(format);
		return (write_left_spaces(str, size));
	}
	return (0);
}
