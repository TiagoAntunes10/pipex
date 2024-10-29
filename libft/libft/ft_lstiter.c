/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 21:07:51 by tialbert          #+#    #+#             */
/*   Updated: 2023/10/06 21:07:53 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst != NULL)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
}

/*
void	f(void *content)
{
	char	*arr;
	int		i;

	arr = (char *) content;
	i = 0;
	while (arr[i] != '\0')
	{
		arr[i] += 1;
		i++;
	}
}

#include <stdio.h>

int	main(void)
{
	t_list	**lst;
	t_list	*lst1;
	t_list	*lst2;
	t_list	*lst3;
	t_list	*new;
	t_list	*current;

	lst = malloc(sizeof(t_list **));
	lst1 = ft_lstnew("aaaaaa");
	ft_lstadd_back(lst, lst1);
	lst2 = ft_lstnew("bbbbbb");
	ft_lstadd_back(lst, lst2);
	lst3 = ft_lstnew("ccccccc");
	ft_lstadd_back(lst, lst3);
	new = ft_lstnew("dddddd");
	ft_lstadd_back(lst, new);
	current = *lst;
	printf("Before:\n");
	while (current != NULL)
	{
		printf("%s\n", (char *) current->content);
		current = current->next;
	}
	printf("\nAfter:\n");
	ft_lstiter(*lst, f);
	current = *lst;
	while (current != NULL)
	{
		printf("%s\n", (char *) current->content);
		current = current->next;
	}
}*/
