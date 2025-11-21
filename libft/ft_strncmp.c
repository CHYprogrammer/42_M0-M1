/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heychong <heychong@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 21:21:00 by heychong          #+#    #+#             */
/*   Updated: 2025/11/16 17:26:05 by heychong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	c1;
	unsigned char	c2;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		c1 = (unsigned char)s1[i];
		c2 = (unsigned char)s2[i];
		if (c1 > c2)
			return (1);
		else if (c1 < c2)
			return (-1);
		i++;
	}
	return (0);
}

/*#include <stdio.h>

int	main()
{
	printf("%d\n", (ft_strncmp("t", "", 0) == 0));
	printf("%d\n", (ft_strncmp("1234", "`1235", 3) == 0));
	printf("%d\n", (ft_strncmp("1234", "1235", 4) < 0));
	printf("%d\n", (ft_strncmp("1234", "1235", -1) < 0));
	printf("%d\n", (ft_strncmp("", "", 42) == 0));
	printf("%d\n", (ft_strncmp("Tripouille", "Tripouille", 42) == 0));
	printf("%d\n", (ft_strncmp("Tripouille", "tripouille", 42) < 0));
	printf("%d\n", (ft_strncmp("Tripouille", "TriPouille", 42) > 0));
	printf("%d\n", (ft_strncmp("Tripouille", "TripouillE", 42) > 0));
	printf("%d\n", (ft_strncmp("Tripouille", "TripouilleX", 42) < 0));
	printf("%d\n", (ft_strncmp("Tripouille", "Tripouill", 42) > 0));
	printf("%d\n", (ft_strncmp("", "1", 0) == 0));
	printf("%d\n", (ft_strncmp("1", "", 0) == 0));
	printf("%d\n", (ft_strncmp("", "1", 1) < 0));
	printf("%d\n", (ft_strncmp("1", "", 1) > 0));
	printf("%d\n", (ft_strncmp("", "", 1) == 0));
}*/
