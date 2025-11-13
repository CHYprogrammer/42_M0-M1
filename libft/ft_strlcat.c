/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heychong <heychong@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 20:34:34 by heychong          #+#    #+#             */
/*   Updated: 2025/11/07 18:12:50 by heychong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	cat_i;

	src_len = 0;
	while (src[src_len])
		src_len++;
	dest_len = 0;
	while (dest[dest_len])
		dest_len++;
	cat_i = 0;
	while (src[cat_i] && (dest_len + cat_i + 1) < size)
	{
		dest[dest_len + cat_i] = src[cat_i];
		cat_i++;
	}
	if (dest_len >= size)
		return (size + src_len);
	return (src_len + dest_len);
}

/*#include <stdio.h>
#include <bsd/string.h>

int	main()
{
	int		mem_size = 6;
	char	dest[30];
	memset(dest, 0, 30);
	memset(dest, '1', mem_size);
	char	dest2[30];
	memset(dest2, 0, 30);
	memset(dest2, '1', mem_size);
	char	*src = "AAAAAAAAA";
	int		cat_size = 7;

	printf("cat_size: %d, mem_size: %d\n", cat_size, mem_size);
	printf("myfunc: %zu ", ft_strlcat(dest, src, cat_size));
	for (size_t i = 0; i < 15 ; i++) {
		if (dest[i] == '\0')
			printf("\\0");
		else
			printf("%c", dest[i]);
	}
	printf("\n");
	printf("expect: %zu ", strlcat(dest2, src, cat_size));
	for (size_t i = 0; i < 15; i++) {
		if (dest2[i] == '\0')
			printf("\\0");
		else
			printf("%c", dest2[i]);
	}
}*/
