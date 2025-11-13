/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heychong <heychong@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 21:17:55 by heychong          #+#    #+#             */
/*   Updated: 2025/11/13 13:48:11 by heychong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
/*#include <string.h>
#include <stdio.h>
int	main(void)
{
	char	*src = "hello world";
	char	*answer = strdup(src);
	char	*dest = ft_strdup(src);

	printf("%s\n%s", answer, dest);
	free(dest);
}*/
