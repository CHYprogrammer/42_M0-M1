/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heychong <heychong@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 09:15:00 by heychong          #+#    #+#             */
/*   Updated: 2025/11/14 16:54:42 by heychong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	count_digit(int nbr)
{
	size_t	count;

	count = 0;
	if (nbr <= 0)
		count++;
	while (nbr)
	{
		nbr /= 10;
		count++;
	}
	return (count);
}

void	convertion_rec(int nbr, char *str, size_t *index)
{
	if (nbr / 10)
		convertion_rec(nbr / 10, str, index);
	if (nbr < 0)
		str[*index] = '0' - (nbr % 10);
	else
		str[*index] = '0' + (nbr % 10);
	(*index)++;
}

char	*ft_itoa(int nbr)
{
	char	*str;
	size_t	digit;
	size_t	index;

	digit = count_digit(nbr);
	str = malloc(digit + 1);
	if (!str)
		return (NULL);
	index = 0;
	if (nbr < 0)
		str[index++] = '-';
	if (nbr == 0)
		str[index++] = '0';
	else
		convertion_rec(nbr, str, &index);
	str[index] = '\0';
	return (str);
}

/*#include <stdio.h>
int	main()
{
	printf("%zu\n", count_digit(-42));
	printf("%s\n", ft_itoa(-42));
}*/
