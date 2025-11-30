/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heyu <heyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 16:39:24 by heychong          #+#    #+#             */
/*   Updated: 2025/11/28 22:28:23 by heyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

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

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	cat_i;

	src_len = 0;
	while (src[src_len])
		src_len++;
	dest_len = 0;
	while (dest_len < size && dest[dest_len])
		dest_len++;
	if (size <= dest_len)
		return (size + src_len);
	cat_i = 0;
	while (src[cat_i] && (dest_len + cat_i + 1) < size)
	{
		dest[dest_len + cat_i] = src[cat_i];
		cat_i++;
	}
	dest[dest_len + cat_i] = '\0';
	return (src_len + dest_len);
}

char	*ft_strdup(const char *str)
{
	char	*dest;
	size_t	i;
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	dest = malloc(len + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (str[i])
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}