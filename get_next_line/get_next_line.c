/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heychong <heychong@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:14:47 by heychong          #+#    #+#             */
/*   Updated: 2025/12/23 22:11:09 by heychong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char	g_buf[BUFFER_SIZE + 1];

int	find_lf(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

void	update_stash(char **stash_ptr, char *remainder)
{
	char	*temp;

	if (!remainder[0])
	{
		free_and_null(stash_ptr);
		return ;
	}
	temp = ft_strdup(remainder);
	if (!temp)
		return ;
	free(*stash_ptr);
	*stash_ptr = temp;
}

char	*ret_line(char **stash_ptr)
{
	char	*line;
	int		nl_len;
	int		nl_pos;
	int		i;

	nl_pos = find_lf(*stash_ptr);
	if (nl_pos >= 0)
		nl_len = nl_pos + 1;
	else
		nl_len = ft_strlen(*stash_ptr);
	line = malloc(nl_len + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (i < nl_len)
	{
		line[i] = (*stash_ptr)[i];
		i++;
	}
	line[i] = '\0';
	if (nl_pos >= 0)
		update_stash(stash_ptr, *stash_ptr + nl_len);
	else
		free_and_null(stash_ptr);
	return (line);
}

char	*handle_end(char **stash_ptr, int r_bytes)
{
	char	*line;

	if (r_bytes < 0 || !*stash_ptr || !(*stash_ptr)[0])
	{
		free_and_null(stash_ptr);
		return (NULL);
	}
	line = ft_strdup(*stash_ptr);
	free_and_null(stash_ptr);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	int			r_bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (stash && find_lf(stash) >= 0)
		return (ret_line(&stash));
	while (!stash || find_lf(stash) < 0)
	{
		r_bytes = read(fd, g_buf, BUFFER_SIZE);
		if (r_bytes <= 0)
			return (handle_end(&stash, r_bytes));
		g_buf[r_bytes] = '\0';
		stash = ft_strjoin_free(stash, g_buf);
	}
	return (ret_line(&stash));
}
