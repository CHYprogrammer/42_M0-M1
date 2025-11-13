/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heychong <heychong@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 21:01:04 by heychong          #+#    #+#             */
/*   Updated: 2025/11/03 17:35:48 by heychong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}
/*
#include <stdio.h>

int	main()
{
	char	s[] = "tripouille";

	printf("%p\n", ft_strchr(s, 't'));
	printf("%p\n", ft_strchr(s, 'l'));
	printf("%p\n", ft_strchr(s, 'z'));
	printf("%p\n", ft_strchr(s, 0));
	printf("%p\n", ft_strchr(s, 't' + 256));
}*/
