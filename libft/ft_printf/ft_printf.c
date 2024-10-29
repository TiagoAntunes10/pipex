/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:25:54 by tialbert          #+#    #+#             */
/*   Updated: 2024/02/01 10:45:54 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	print_str(const char *str, va_list valst);
static int	str_adv(const char *str);

int	ft_printf(const char *str, ...)
{
	va_list	valst;
	int		count;

	va_start(valst, str);
	count = print_str(str, valst);
	va_end(valst);
	return (count);
}

static int	print_str(const char *str, va_list valst)
{
	int	count;

	count = 0;
	while (*str != '\0')
	{
		if (*str == '%')
		{
			count = write_spe(++str, valst, count);
			str += str_adv(str);
		}
		else
			write(2, str, 1);
		count++;
		str++;
	}
	return (count);
}

static int	str_adv(const char *str)
{
	unsigned int	i;

	i = 0;
	while (ft_isalpha(str[i]) == 0 && str[i] != '%')
		i++;
	return (i);
}
