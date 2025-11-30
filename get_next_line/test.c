/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heyu <heyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 16:39:31 by heyu              #+#    #+#             */
/*   Updated: 2025/11/28 11:28:27 by heyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int	main()
{
	int	fd = open("a.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		return 1;
	}
	int		BUFFER_SIZE = 1000;
	char	buf[BUFFER_SIZE];
	ssize_t	n = read(fd, buf, BUFFER_SIZE - 1);
	if (n == -1)
	{
		perror("read");
		close(fd);
		return 1;
	}
	buf[n] = '\0';
	printf("Read Data: %s\n", buf);
	close (fd);
}