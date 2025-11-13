/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heychong <heychong@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 21:42:15 by heychong          #+#    #+#             */
/*   Updated: 2025/11/07 19:10:43 by heychong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

const char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	big_i;
	size_t	little_i;
	char	*empty = "";
	char	*null = "\0";

	if (little == null || little == empty)
		return (big);
	big_i = 0;
	while (big[big_i] && big_i < len)
	{
		little_i = 0;
		while (little[little_i] == big[big_i + little_i]
			&& big_i + little_i < len)
			little_i++;
		if (little[little_i] == '\0')
			return (big + big_i);
		big_i++;
	}
	return (NULL);
}

/*#include <stdio.h>
#include <bsd/string.h>

int	main(void)
{
	char	haystack[30] = "aaabcabcd";
	char	needle[10] = "aabc";

	printf("haystack: %s\n", haystack);
	printf("[2] needle: %s, len: -1\n    my_func: %s\n", needle, ft_strnstr(haystack, needle, -1));
	printf("    expected: %s\n", strnstr(haystack, needle, -1));
	printf("[5] needle: EMPTY, len: -1\n    my_func: %s\n", ft_strnstr(haystack, "", -1));
	printf("    expected: %s\n", strnstr(haystack, "", -1));
	printf("[6] needle: EMPTY, len: 0\n    my_func: %s\n", ft_strnstr(haystack, "", 0));
	printf("    expected: %s\n", strnstr(haystack, "", 0));
	printf("[10] needle: abcd, len: 9\n    my_func: %s\n", ft_strnstr(haystack, "abcd", 9));
	printf("    expected: %s\n", strnstr(haystack, "abcd", 9));

	printf("[test] needle: null char, len: 0\n    my_func: %s\n", ft_strnstr(haystack, "\0", 0));
	printf("    expected: %s\n", strnstr(haystack, "\0", 0));
}*/
