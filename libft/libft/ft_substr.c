/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 08:52:36 by tialbert          #+#    #+#             */
/*   Updated: 2024/01/25 11:22:35 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// static int	check_slash(char const *s, size_t len)
// {
// 	int		count;
// 	size_t	i;

// 	count = 0;
// 	i = 0;
// 	while (i < len)
// 	{
// 		if (*(s - 1) == '\\' && *s == '\\'
// 			&& (*(s + 1) == '\'' || *(s + 1) == '"'))
// 			count++;
// 		s++;
// 		i++;
// 	}
// 	return (count);
// }

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (len == 0 || start >= (unsigned int) ft_strlen(s))
	{
		str = malloc(1);
		if (str == 0)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	if (*s == '"' || *s == '\'')
	{
		s++;
		len--;
	}
	if (len <= (size_t)(ft_strlen(s) - start))
		str = malloc(len + 1);
	else
		str = malloc((ft_strlen(s) - start) + 1);
	if (str == 0)
		return (NULL);
	if (len > (size_t) ft_strlen(s))
		len = ft_strlen(s);
	ft_strlcpy(str, s + start, len + 1);
	return (str);
}
