/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_ap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heychong <heychong@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 19:52:51 by heychong          #+#    #+#             */
/*   Updated: 2026/01/18 21:29:06 by heychong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//itoa関数
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
	char	c;

	if (nbr / 10)
		convertion_rec(nbr / 10, str, index);
	if (nbr < 0)
		c = '0' - (nbr % 10);
	else
		c = '0' + (nbr % 10);
	str[*index] = c;
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

//utoa関数
size_t	count_digit_base(unsigned long long unbr, int base)
{
	size_t	count;

	if (unbr == 0)
		return (1);
	count = 0;
	while (unbr)
	{
		count++;
		unbr /= base;
	}
	return (count);
}

char	*ft_itou_base(unsigned long long unbr, char *base)
{
	char			*str;
	size_t			digit;
	size_t			index;
	unsigned int	base_len;

	base_len = 0;
	while (base[base_len])
		base_len++;
	digit = count_digit_base(unbr, base_len);
	str = malloc(digit + 1);
	if (!str)
		return (NULL);
	index = digit;
	while (index--)
	{
		str[index] = base[unbr % base_len];
		unbr /= base_len;
	}
	str[digit] = '\0';
	return (str);
}
