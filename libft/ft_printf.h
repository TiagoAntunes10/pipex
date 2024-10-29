/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:49:57 by tialbert          #+#    #+#             */
/*   Updated: 2023/12/18 10:03:35 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include <stdarg.h>
#include <unistd.h>

int				ft_printf(const char *str, ...);
int				write_spe(const char *str, va_list valst, int count);
int				write_c(va_list valst, int count, char *format);
int				write_s(va_list valst, int count, char *format);
int				nb_len(int long nb);
int				write_d_i(va_list valst, int count, char *format);
int				ft_putnbr_base(unsigned int nb, char *base);
int				write_u(va_list valst, int count, char *format);
int				write_p(va_list valst, int count, char *format);
int				write_x_lower(va_list valst, int count, char *format);
int				write_x_upper(va_list valst, int count, char *format);
int				write_ptr(unsigned long long ptr, char *base, int div);
unsigned int	base_len(unsigned int nb);
int				write_bonus(const char *str, va_list valst, int count);
void			write_char(unsigned int size, char c);
int				write_unsigned_bonus(unsigned long int nb, int count,
					char *format, long int size_precision);
void			write_nbr(unsigned long int nb, int fd);
int				write_left_nb(int long nb, unsigned int size, int count,
					long int size_precision);
int				write_precision_nb(int long nb, unsigned int size, int count);
int				write_zero_nb(int long nb, unsigned int size, int count,
					long int size_precision);
int				write_left_space(int long nb, unsigned int size, int count,
					long int size_precision);
long int		check_precision(char *format);
int				nb_len_positive(int long nb);
int				write_space_base_x(int long nb, unsigned int size, int count,
					long int size_precision);
int				write_left_base_x(unsigned long int nb, unsigned int size,
					int count, long int size_precision);
int				write_precision_base_x(unsigned long int nb, unsigned int size,
					int count);
int				write_zero_base_x(unsigned long int nb, unsigned int size,
					int count, long int size_precision);
int				write_space_base_x_upper(int long nb, unsigned int size,
					int count, long int size_precision);
int				write_left_base_x_upper(unsigned long int nb, unsigned int size,
					int count, long int size_precision);
int				write_precision_base_x_upper(unsigned long int nb,
					unsigned int size, int count);
int				write_zero_base_x_upper(unsigned long int nb, unsigned int size,
					int count, long int size_precision);
int				write_nil_left(unsigned int size);
int				skip_minus(char *format);
