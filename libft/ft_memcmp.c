/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heychong <heychong@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 21:29:44 by heychong          #+#    #+#             */
/*   Updated: 2025/10/24 16:33:09 by heychong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	if (n == 0)
		return (0);
	i = 0;
	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	while (i < n)
	{
		if (ptr1[i] != ptr2[i])
			return (ptr1[i] - ptr2[i]);
		i++;
	}
	return (0);
}

/*#include <stdio.h>
#include <string.h>

int	main(void)
{
	int	arr[6] = {1, 0, 4, 5, -42};
	int	arr2[6] = {1, 0, 6, 8, -42};
	int	mine = ft_memcmp(arr, arr2, 5 * sizeof(int));
	int	offic = memcmp(arr, arr2, 5 * sizeof(int));

	printf("%d %d", mine, offic);
}*/
