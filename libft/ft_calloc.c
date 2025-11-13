/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heychong <heychong@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 22:19:16 by heychong          #+#    #+#             */
/*   Updated: 2025/11/13 13:33:41 by heychong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*arr;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (nmemb > SIZE_MAX / size)
		return (NULL);
	arr = malloc(nmemb * size);
	if (!arr)
		return (NULL);
	ft_memset(arr, 0, nmemb * size);
	return (arr);
}

/*#include <stdio.h>
#include <string.h>
#include <limits.h>

int	main()
{
	printf("%d", (ft_calloc(INT_MIN, INT_MIN) == NULL));
}*/
