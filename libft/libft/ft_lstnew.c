/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:35:41 by tialbert          #+#    #+#             */
/*   Updated: 2023/10/03 11:35:42 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*lst;
	char	*arr;
	char	*arr2;
	int		i;

	lst = malloc(sizeof(t_list *));
	lst->content = malloc(sizeof(void *));
	arr = (char *) content;
	arr2 = (char *) lst->content;
	i = 0;
	while (arr[i] != '\0')
	{
		arr2[i] = arr[i];
		i++;
	}
	lst->next = NULL;
	return (lst);
}

/*
#include <stdio.h>

int	main(void)
{
	struct s_list	lst;
	t_list			*lst1;
	char			*str;

	str = "ashdb";
	lst1 = &lst;
	lst1 = ft_lstnew(str);
	printf("%s\n", (char *) (*lst1).content);
}*/