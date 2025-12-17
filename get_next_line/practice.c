/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   practice.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heychong <heychong@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 18:50:40 by heychong          #+#    #+#             */
/*   Updated: 2025/12/17 19:16:25 by heychong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

char	*gnl(int fd)
{
	char	buf;
	char	*result;
	int		read_byte;
	int		i;

	result = malloc(BUFFER_SIZE + 1);
	if (!result)
		return (NULL);
	read_byte = read(fd, &buf, 1);
	i = 0;
	while (read_byte <= 0 && buf != '\n')
	{
		if (i >= BUFFER_SIZE)
			result = realloc(result, BUFFER_SIZE, BUFFER_SIZE * 2);
		if (!result)
			return (NULL);
		result[i++] = buf;
		read_byte = read(fd, &buf, 1);
	}
	if (read_byte == 0 && i <= 0)
	{
		free(result);
		return (NULL);
	}
	if (buf == '\n')
		result[i++] = '\n';
	result[i] = '\0';
	return (result);
}