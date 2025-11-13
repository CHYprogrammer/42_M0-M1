/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heychong <heychong@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 17:42:54 by heychong          #+#    #+#             */
/*   Updated: 2025/10/30 19:44:56 by heychong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

void	*ft_memset(void *ptr, int value, size_t n)
{
	size_t			i;
	unsigned char	*p;
	unsigned char	s;

	i = 0;
	p = (unsigned char *)ptr;
	s = (unsigned char)value;
	while (i < n)
	{
		p[i] = s;
		i++;
	}
	return (ptr);
}
