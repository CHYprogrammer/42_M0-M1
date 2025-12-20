/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heychong <heychong@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:14:47 by heychong          #+#    #+#             */
/*   Updated: 2025/12/20 16:09:20 by heychong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char	*ft_strdup(const char *s)
{
	char	*dest;
	size_t	i;

	dest = malloc(ft_strlen(s) + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*res;
	int		len;
	int		i;
	int		j;

	len = ft_strlen(s1) + ft_strlen(s2);
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		res[i + j] = s2[j];
		j++;
	}
	res[i + j] = '\0';
	if (s1)
		free(s1);
	return (res);
}

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
	return (0);
}

void	update_stash(char *remainder)
{
	static char	*stash;
	char		*temp;
	int			i;

	if (!remainder[0])
	{
		free(stash);
		stash = NULL;
		return ;
	}
	temp = ft_strdup(remainder);
	if (!temp)
		return ;
	free(stash);
	stash = temp;
}

char	*get_line(char *stash)
{
	char	*line;
	int		nl_pos;
	int		i;

	nl_pos = find_lf(stash);
	line = malloc(nl_pos + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (i < nl_pos)
		line[i++] = stash[i];
	line[i] = '\0';
	update_stash(stash + nl_pos + 1);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		buf[BUFFER_SIZE + 1];
	int			r_bytes;

	if (stash && find_lf(stash))
		return (get_line(stash));
	while (!stash || !find_lf(stash))
	{
		r_bytes = read(fd, buf, BUFFER_SIZE);
		if (r_bytes <= 0)
			return (handle_end(stash));
		buf[r_bytes] = '\0';
		stash = ft_strjoin_free(stash, buf);
	}
	return (get_line(stash));
}