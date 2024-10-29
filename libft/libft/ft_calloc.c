/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:32:36 by tialbert          #+#    #+#             */
/*   Updated: 2023/10/03 11:32:37 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(size_t nmem, size_t size)
{
	void		*arr;
	long int	n;

	if (nmem == 0 || size == 0)
		return (NULL);
	n = nmem * size;
	if (n > 2147483647)
		return (NULL);
	arr = malloc (nmem * size);
	return (arr);
}
