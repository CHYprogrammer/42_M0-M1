/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heyu <heyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:14:47 by heychong          #+#    #+#             */
/*   Updated: 2025/12/10 10:10:15 by heyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	strlen_nl(char *str)
{
	size_t	nl_len;

	nl_len = 0;
	while (str[nl_len] && str[nl_len] != '\n')
		nl_len++;
	return (nl_len);
}

char	*get_next_line(int fd)
{
	char		buff[BUFFER_SIZE + 1];
	static char	stash[BUFFER_SIZE * 2 + 1];
	char		*result;
	int			read_bytes;
	size_t		nl_i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	nl_i = strlen_nl(stash);
	if (stash[nl_i] == '\n')
	{
		result = malloc(nl_i + 2);
		if (!result)
			return (NULL);
		ft_strlcpy(result, stash, nl_i + 2);
		ft_strlcpy(stash, stash + nl_i + 1, ft_strlen(stash));
		return (result);
	}
	read_bytes = read(fd, buff, BUFFER_SIZE);
	if (read_bytes == 0)
	{
		if (stash[0])
		{
			result = ft_strdup(stash);
			stash[0] = '\0';
			return (result);
		}
		return (NULL);
	}
	else if (read_bytes < 0)
		return (NULL);
	buff[read_bytes] = '\0';
	nl_i += strlen_nl(buff);
	if (buff[strlen_nl(buff)] == '\n')
		nl_i++;
	ft_strlcat(stash, buff, nl_i + 1);
	result = malloc(nl_i + 1);
	if (!result)
		return (NULL);
	ft_strlcpy(result, stash, nl_i + 1);
	ft_strlcpy(stash, buff + nl_i, ft_strlen(buff) - strlen_nl(buff) + 1);
	return (result);
}

/*#include <stdio.h>
#include <fcntl.h>

int	main()
{
	int	fd = open("a.txt", O_RDONLY);
	if (fd == -1)
		return (1);
	char	*first = get_next_line(fd);
	printf("%s\n", first);
	char	*second = get_next_line(fd);
	printf("%s\n", second);
	char	*third = get_next_line(fd);
	printf("%s\n", third);
	third = get_next_line(fd);
	printf("%s\n", third);
	third = get_next_line(fd);
	printf("%s\n", third);
	close(fd);
	return (0);
}*/