/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_spe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:26:04 by tialbert          #+#    #+#             */
/*   Updated: 2023/12/18 10:10:22 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	write_perc(void);

int	write_spe(const char *str, va_list valst, int count)
{
	if (*str == 'c')
		return (write_c(valst, count, ""));
	else if (*str == 's')
		return (write_s(valst, count, "") - 1);
	else if (*str == 'p')
		return (write_p(valst, count, "") - 1);
	else if (*str == 'd' || *str == 'i')
		return (write_d_i(valst, count, "") - 1);
	else if (*str == 'u')
		return (write_u(valst, count, "") - 1);
	else if (*str == 'x')
		return (write_x_lower(valst, count, "") - 1);
	else if (*str == 'X')
		return (write_x_upper(valst, count, "") - 1);
	else if (*str == '-' || *str == '0' || *str == '.' || *str == '#'
		|| *str == ' ' || *str == '+' || ft_isdigit(*str) > 0)
		return (write_bonus(str++, valst, count));
	else if (*str == '%')
		return (count + write_perc());
	return (count);
}

static int	write_perc(void)
{
	ft_putchar_fd('%', 1);
	return (0);
}
