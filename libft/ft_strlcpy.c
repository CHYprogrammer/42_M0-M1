/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heyu <heyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 18:46:04 by heychong          #+#    #+#             */
/*   Updated: 2025/11/28 20:55:49 by heyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	len;

	src_len = 0;
	while (src[src_len])
		src_len++;
	if (!dst || !size)
		return (src_len);
	len = 0;
	while (src[len] && len + 1 < size)
	{
		dst[len] = src[len];
		len++;
	}
	dst[len] = '\0';
	return (src_len);
}
/*
#include <stdio.h>
#include <string.h>

int	main()
{
	char	src[] = "coucou";
	char	dest[10];
	memset(dest, 'A', 10);
	printf("%zu ", ft_strlcpy(dest, src, 0));
	printf("%s\n", dest);
	printf("%zu ", ft_strlcpy(dest, src, 1));
	printf("%s\n", dest);
	printf("%zu ", ft_strlcpy(dest, src, 2));
	printf("%s\n", dest);
	printf("%zu ", ft_strlcpy(dest, src, -1));
	printf("%s\n", dest);
	printf("%zu ", ft_strlcpy(dest, src, 6));
	printf("%s\n", dest);
	printf("%zu ", ft_strlcpy(dest, src, 7));
	printf("%s\n", dest);
	printf("%zu ", ft_strlcpy(dest, src, 8));
	printf("%s\n", dest);
	printf("%zu ", ft_strlcpy(dest, "", 42));
	printf("%s\n", dest);
	printf("%zu ", ft_strlcpy(dest, "1", 0));
	printf("%s\n", dest);
}*/
