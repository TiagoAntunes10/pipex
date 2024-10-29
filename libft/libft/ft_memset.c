/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 11:56:02 by tialbert          #+#    #+#             */
/*   Updated: 2023/10/01 11:56:05 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned int	i;
	char			*cs;

	cs = (char *) s;
	i = 0;
	while (i < n)
	{
		cs[i] = c;
		i++;
	}
	return (cs);
}

/*
#include <string.h>
int main(void)
{
    char            str [] = "fhbfdh dhfhbhoasj nhahb";
    char            str2 [] = "fhbfdh dhfhbhoasj nhahb";
    unsigned int    n;
    char            c;
    int             arr[7];
    int             arr2[7];
	int				*arr3;
	int				*arr4;
	int				a;
	int				b;
    unsigned int    i;

	arr3 = &a;
	arr4 = &b;
    c = 0;
    n = 7;
    printf("ft_memset_str: %s\n",
		(char *) ft_memset(str + 6, c, sizeof(char) * n));
    printf("memset_str: %s\n",
		(char *) memset(str2 + 6, c, sizeof(char) * n));
    arr3 = (int *) ft_memset(arr, c, sizeof(int) * n);
    arr4 = (int *) memset(arr2, c, sizeof(int) * n);
    i = 0;
	printf("ft_memset_arr: ");
    while (i < n)
    {
        printf("%d, ", arr3[i]);
        i++;
    }
    printf("\n");
    i = 0;
	printf("memset_arr: ");
    while (i < n)
    {
        printf("%d, ", arr4[i]);
        i++;
    }
    printf("\n");
}*/
