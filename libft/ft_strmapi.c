/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heychong <heychong@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 14:22:15 by heychong          #+#    #+#             */
/*   Updated: 2025/10/29 15:52:00 by heychong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *str, char (*function)(unsigned int, char))
{
	char	*map;
	size_t	index;

	if (!str && !function)
		return (NULL);
	map = malloc(ft_strlen(str) + 1);
	if (!map)
	{
		free(map);
		return (NULL);
	}
	index = 0;
	while (str[index])
	{
		map[index] = function(index, str[index]);
		index++;
	}
	map[index] = '\0';
	return (map);
}
