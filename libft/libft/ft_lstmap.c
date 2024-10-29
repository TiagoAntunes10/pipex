/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 21:06:46 by tialbert          #+#    #+#             */
/*   Updated: 2023/10/06 21:06:50 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//void	del(void *content);

t_list	*ft_lstmap(t_list *lst, void *(*f) (void *), void (*del) (void *))
{
	t_list	**lst2;
	t_list	*lst3;

	lst2 = malloc(sizeof(t_list **));
	while (lst != NULL)
	{
		lst3 = ft_lstnew((*f)(lst->content));
		if (lst3 == NULL)
		{
			ft_lstdelone(lst3, del);
			break ;
		}
		ft_lstadd_back(lst2, lst3);
		lst = lst->next;
	}
	return (*lst2);
}

/*
void	*f(void *content)
{
	char	*arr;
	char	*arr2;
	int		i;

	arr = (char *) content;
	arr2 = malloc(sizeof(arr));
	i = 0;
	while (arr[i] != '\0')
	{
		arr2[i] = arr[i] + 1;
		i++;
	}
	return (arr2);
}

void	del(void *content)
{
	free(content);
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
	*lst = ft_lstmap(*lst, f, del);
	current = *lst;
	while (current != NULL)
	{
		printf("%s\n", (char *) current->content);
		current = current->next;
	}
}*/
