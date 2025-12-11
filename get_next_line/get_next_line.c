/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heychong <heychong@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:14:47 by heychong          #+#    #+#             */
/*   Updated: 2025/12/11 20:56:15 by heychong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

int	func(char *dest, char *src, char *str)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		if (src[i] == '\n')
		{
			ft_strlcpy(str, src + i);
			return (i);
		}
		i++;
	}
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		buf[BUFFER_SIZE + 1];
	char		*result;
	int			read_bytes;
	int			i;

	if (stash[0])
		i = func(result, stash, stash);
	if (src[i] == '\n')
		return (result);
	read_bytes = read(fd, buf, BUFFER_SIZE);
	buf[read_bytes] = '\0';
	if (read_bytes <= 0)
		return (NULL);
	if (buf[func(result + i, buf, str)])
		return (result);
	ft_strlcat(stash, buf);
}
