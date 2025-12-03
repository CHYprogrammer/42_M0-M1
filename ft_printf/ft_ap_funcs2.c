/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ap_funcs2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heyu <heyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 15:51:43 by heyu              #+#    #+#             */
/*   Updated: 2025/12/03 20:29:53 by heyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	count_hex_digit(unsigned int unbr)
{
	unsigned int	digit;

	digit = 1;
	while (unbr / 16)
	{
		digit++;
		unbr /= 16;
	}
	return (digit);
}

char	*ft_itox(unsigned int digit, char *base, unsigned int unbr)
{
	char			*hex;
	unsigned int	i;

	hex = malloc(digit + 1);
	if (!hex)
		return (NULL);
	i = 1;
	while (unbr)
	{
		hex[digit - i] = base[unbr % 16];
		unbr /= 16;
		i++;
	}
	hex[digit] = '\0';
	return (hex);
}

int	print_hex_ap(char spec, unsigned int unbr)
{
	unsigned int	digit;
	char			*hex;
	char			base[17];
	int				len;
	int				ret;

	digit = count_hex_digit(unbr);
	base = "0123456789ABCDEF";
	if (spec == 'x')
		base = "0123456789abcdef";
	hex = ft_itox(digit, base, unbr);
	ret = print_str_ap(hex);
	if (hex)
		free(hex);
	return (ret);
}