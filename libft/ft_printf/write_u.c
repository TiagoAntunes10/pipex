/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:26:52 by tialbert          #+#    #+#             */
/*   Updated: 2023/12/18 10:10:38 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	write_u(va_list valst, int count, char *format)
{
	unsigned int	nb;
	long int		size_precision;

	nb = va_arg(valst, unsigned long int);
	size_precision = check_precision(format);
	if (size_precision < nb_len_positive(nb) && size_precision >= 0 && nb != 0)
		size_precision = nb_len_positive(nb);
	if (*format == '-' || *format == '.' || ft_isdigit(*format) > 0)
		return (count + write_unsigned_bonus(nb, 0, format, size_precision));
	else if (*format == 0)
	{
		write_nbr(nb, 1);
		return (count + nb_len(nb));
	}
	return (count);
}
