/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heychong <heychong@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 16:39:24 by heychong          #+#    #+#             */
/*   Updated: 2025/12/11 18:14:00 by heychong         ###   ########.fr       */
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

size_t	ft_strlcpy(char *dst, char *src)
{
	size_t	src_len;
	size_t	len;

	src_len = 0;
	while (src[src_len])
		src_len++;
	if (!dst)
		return (src_len);
	len = 0;
	while (src[len])
	{
		dst[len] = src[len];
		len++;
	}
	dst[len] = '\0';
	return (src_len);
}

size_t	ft_strlcat(char *dest, char *src)
{
	size_t	dest_len;
	size_t	cat_i;

	dest_len = ft_strlen(dest);
	cat_i = 0;
	while (src[cat_i])
	{
		dest[dest_len + cat_i] = src[cat_i];
		cat_i++;
	}
	dest[dest_len + cat_i] = '\0';
	return (cat_i + dest_len);
}
