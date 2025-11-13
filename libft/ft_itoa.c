/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heychong <heychong@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 09:15:00 by heychong          #+#    #+#             */
/*   Updated: 2025/10/29 15:50:53 by heychong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	count_digit(int nbr)
{
	size_t	digit_count;

	digit_count = 0;
	while (nbr)
	{
		digit_count++;
		nbr /= 10;
	}
return (digit_count);
}

char	*just_free(char	*str)
{
	free(str);
	return (NULL);
}

char	*ft_itoa(int nbr)
{
	size_t	ndig;
	char	*converted;
	size_t	converted_i;
	size_t	index_min;

	ndig = count_digit(nbr);
	converted = malloc (sizeof(char) * (ndig + 1));
	if (!converted)
		return (just_free(converted));
	converted_i = 0;
	index_min = 0;
	if (nbr < 0)
	{
		nbr = -nbr;
		converted[converted_i] = '-';
		index_min = 1;
	}
	converted[ndig] = '\0';
	while (ndig > index_min)
	{
		converted[ndig - 1] = '0' + nbr % 10;
		ndig--;
	}
	return (converted);
}

#include <stdio.h>
//int	main()
//{printf("%zu", count_digit(-42));}
