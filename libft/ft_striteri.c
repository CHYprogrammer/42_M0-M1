/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heychong <heychong@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 16:34:52 by heychong          #+#    #+#             */
/*   Updated: 2025/11/03 17:04:35 by heychong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *str, void (*function)(unsigned int, char*))
{
	size_t	index;

	index = 0;
	if (!str || !function)
		return ;
	while (str[index])
	{
		function(index, &str[index]);
		index++;
	}
}
