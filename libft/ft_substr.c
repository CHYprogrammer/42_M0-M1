/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heychong <heychong@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 16:18:33 by heychong          #+#    #+#             */
/*   Updated: 2025/11/13 14:52:51 by heychong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, size_t start, size_t len)
{
	char	*sub;
	size_t	i;

	if (start >= ft_strlen(s))
	{
		sub = (char *)malloc(1);
		sub[0] = '\0';
		return (sub);
	}
	if (len >= ft_strlen(s))
		len = ft_strlen(s) - start;
	sub = (char *)malloc(len + 1);
	if (!sub)
		return (NULL);
	i = 0;
	while (s[start + i] && i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("%s", ft_substr("hello world", 100, 4));
}*/
