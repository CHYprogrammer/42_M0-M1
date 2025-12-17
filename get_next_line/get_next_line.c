/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heychong <heychong@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:14:47 by heychong          #+#    #+#             */
/*   Updated: 2025/12/17 20:08:10 by heychong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char	*get_line(char *stash, int nllen)
{
	char	*result;
	int		i;

	result = malloc(nllen + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (i < nllen)
	{
		result[i] = stash[i];
		i++;
	}
	result[i] = '\0';
	i = 0;
	while (stash[nllen])
	{
		stash[i] = stash[nllen];
		i++;
		nllen++;
	}
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		buf[BUFFER_SIZE + 1];
	int			nllen;
	int			read_types;

	if (stash)
	{
		nllen = linelen(stash);
		if (stash[nllen - 1] == '\n')
			return (get_line(stash, nllen));
	}
	read_types = read(fd, buf, BUFFER_SIZE);
	if (read_types > 0)
	{
		buf[read_types] = '\0';
		stash = ft_strjoin(stash, buf);
		nllen = linelen(stash);
		if (stash[nllen - 1] == '\n')
			return (get_line(stash, nllen));
		else
			return (get_next_line(fd));
	}
	else if (read_types == 0 && stash && stash[0])
		return (stash);
	else if (read_types <= 0 && stash)
	{
		free(stash)
		stash = NULL;
	}
	return (NULL);
}
