/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 15:21:01 by tialbert          #+#    #+#             */
/*   Updated: 2023/09/29 15:21:03 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	write_nbr(long int nb, int fd);

void	ft_putnbr_fd(int n, int fd)
{
	long int	j;

	j = n;
	if (j < 0)
	{
		write(fd, "-", 1);
		j *= -1;
	}
	write_nbr(j, fd);
	return ;
}

static void	write_nbr(long int nb, int fd)
{
	int	div;
	int	mod;

	div = nb / 10;
	mod = nb % 10;
	if (div == 0)
	{
		mod += 48;
		write(fd, &mod, 1);
		return ;
	}
	else
		write_nbr(div, fd);
	mod += 48;
	write(fd, &mod, 1);
	return ;
}

/*int main(void)
{
	int	nb;

	nb = -2147483648;
	ft_putnbr_fd(nb, 1);
}*/