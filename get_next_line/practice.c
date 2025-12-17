/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   practice.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heychong <heychong@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 18:50:40 by heychong          #+#    #+#             */
/*   Updated: 2025/12/17 20:24:25 by heychong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strjoin(char *s1, char *s2)
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

int	check_lf(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*get_line(char *stash)
{
	char	*result;
	char	*tmp;
	int		i;
	int		j;

	result = malloc(ft_strlen(stash) + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (stash[i])
	{
		result[i] = stash[i];
		if (stash[i] == '\n')
			break;
		i++;
	}
	result[i] = '\0';
	tmp = malloc(ft_strlen(stash) + 1);
	j = 0;
	while (tmp && stash[i + j])
	{
		tmp[j] = stash[i + j];
		i++;
	}
	if (stash)
	{
		free(stash);
		stash = NULL;
	}
	stash = ft_strdup(tmp);
	return (result);
}

char	*gnl(int fd, char *buf, char **stash_ptr)
{
	int	read_types;

	read_types = read(fd, buf, BUFFER_SIZE);
	if (read_types == 0 && *stash_ptr && *stash_ptr[0])
		return (*stash_ptr);
	else if (read_types <= 0)
		return (NULL);
	else
	{
		*stash_ptr = ft_strjoin(*stash_ptr, buf);
		if (!check_lf(*stash_ptr))
			return (gnl(fd, buf, *stash_ptr));
		else
			return (get_line(*stash_ptr));
	}
}

char	*get_next_line(int fd)
{
	static char *stash;
	char		buf[BUFFER_SIZE + 1];

	if (stash && stash[0] && check_lf(stash))
			return (get_line(stash));
	return (gnl(fd, buf, &stash));
}