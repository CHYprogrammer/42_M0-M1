/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heyu <heyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 19:58:57 by heyu              #+#    #+#             */
/*   Updated: 2025/12/08 17:21:43 by heyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	count_u_digit_base(unsigned int base, unsigned int unbr)
{
	size_t	digit;

	digit = 1;
	while (unbr / base)
	{
		digit++;
		unbr /= base;
	}
	return (digit);
}

void	convertion_u_rec(unsigned int unbr, char *str, size_t *index)
{
	if (unbr / 10)
		convertion_u_rec(unbr / 10, str, index);
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
	digit = count_u_digit_base(10, unbr);
	str = malloc(digit + 1);
	if (!str)
		return (NULL);
	index = 0;
	convertion_u_rec(unbr, str, &index);
	str[index] = '\0';
	return (str);
}