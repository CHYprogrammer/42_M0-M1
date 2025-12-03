/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heyu <heyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 19:58:57 by heyu              #+#    #+#             */
/*   Updated: 2025/12/03 20:17:09 by heyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	count_digit(unsigned int unbr)
{
	size_t	digit;

	digit = 1;
	while (unbr / 10)
	{
		digit++;
		unbr /= 10;
	}
	return (digit);
}

void	convertion_rec(unsigned int unbr, char *str, size_t *index)
{
	if (unbr / 10)
		convertion_rec(unbr / 10, str, index);
	str[*index] = '0' + (unbr % 10);
	(*index)++;
}

char	*ft_utoa(unsigned int unbr)
{
	char	*str;
	size_t	digit;
	size_t	index;

	if (unbr == 0)
		return ("0");
	digit = count_digit(unbr);
	str = malloc(digit + 1);
	if (!str)
		return (NULL);
	index = 0;
	convertion_rec(unbr, str, &index);
	str[index] = '\0';
	return (str);
}