/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:49:29 by tialbert          #+#    #+#             */
/*   Updated: 2023/12/18 10:05:19 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char	*format_str(const char *str);

int	write_bonus(const char *str, va_list valst, int count)
{
	char	*format;

	format = format_str(str);
	if (format[ft_strlen(format) - 1] == 'c')
		return (write_c(valst, count, format));
	else if (format[ft_strlen(format) - 1] == 's')
		return (write_s(valst, count, format) - 1);
	else if (format[ft_strlen(format) - 1] == 'p')
		return (write_p(valst, count, format) - 1);
	else if (format[ft_strlen(format) - 1] == 'd'
		|| format[ft_strlen(format) - 1] == 'i')
		return (write_d_i(valst, count, format) - 1);
	else if (format[ft_strlen(format) - 1] == 'u')
		return (write_u(valst, count, format) - 1);
	else if (format[ft_strlen(format) - 1] == 'x')
		return (write_x_lower(valst, count, format) - 1);
	else if (format[ft_strlen(format) - 1] == 'X')
		return (write_x_upper(valst, count, format) - 1);
	else if (format[ft_strlen(format) - 1] == '%')
		return (write_spe((format + ft_strlen(format) - 1), valst, count));
	else
		return (count);
}

static char	*format_str(const char *str)
{
	unsigned int	i;

	i = 0;
	while (ft_isalpha(str[i]) == 0 && str[i] != '%')
		i++;
	return (ft_substr(str, 0, i + 1));
}

int	skip_minus(char *format)
{
	int	i;

	i = 0;
	while (ft_isdigit(format[i]) == 0 && format[i] != '.'
		&& ft_isalpha(format[i]) == 0)
		i++;
	return (i);
}
