/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heychong <heychong@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 21:15:36 by heychong          #+#    #+#             */
/*   Updated: 2025/11/04 17:12:49 by heychong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	rev_i;

	rev_i = 0;
	while (s[rev_i])
		rev_i++;
	while (rev_i >= 0)
	{
		if (s[rev_i] == (char)c)
			return ((char *)s + rev_i);
		rev_i--;
	}
	return (0);
}

/*#include <stdio.h>

int	main()
{
	char	*s = "tripouille";
	char	*s2 = "ltripouiel";
	char	*s3 = "";

	printf("%p\n", ft_strrchr(s, 't'));
	printf("%p\n", ft_strrchr(s, 'l'));
	printf("%p\n", ft_strrchr(s2, 'l'));
	printf("%p\n", ft_strrchr(s, 'z'));
	printf("%p\n", ft_strrchr(s, '0'));
	printf("%p\n", ft_strrchr(s, 't' + 256));
	printf("%p\n", ft_strrchr(s3, 0));
}*/
