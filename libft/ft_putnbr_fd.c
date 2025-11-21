/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heychong <heychong@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 17:28:25 by heychong          #+#    #+#             */
/*   Updated: 2025/11/16 20:27:14 by heychong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	*str;
	size_t	len;

	str = ft_itoa(n);
	len = 0;
	while (str[len])
		len++;
	write(fd, str, len);
	if (str)
		free(str);
}

/*#include <limits.h>
int	main()
{
	ft_putnbr_fd(INT_MIN - 1, 1);
}*/
