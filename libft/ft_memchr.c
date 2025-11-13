/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heychong <heychong@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 21:24:10 by heychong          #+#    #+#             */
/*   Updated: 2025/11/03 17:14:15 by heychong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

void	*ft_memchr(const void *arr, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;
	unsigned char	input;

	ptr = (unsigned char *)arr;
	input = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == input)
			return (&ptr[i]);
		i++;
	}
	return (NULL);
}
