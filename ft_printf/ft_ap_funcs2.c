/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ap_funcs2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heychong <heychong@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 15:51:43 by heyu              #+#    #+#             */
/*   Updated: 2025/12/17 14:06:14 by heychong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itox(unsigned int digit, unsigned int unbr, char *base)
{
	char			*hex;
	unsigned int	i;

	hex = malloc(digit + 2 + 1);
	if (!hex)
		return (NULL);
	i = 1;
	hex[0] = '0';
	hex[1] = 'x';
	while (unbr)
	{
		hex[digit - i + 2] = base[unbr % 16];
		unbr /= 16;
		i++;
	}
	hex[digit + 2] = '\0';
	return (hex);
}

int	print_hex_ap(char spec, unsigned int unbr)
{
	unsigned int	digit;
	char			*hex;
	int				ret;

	if (unbr == 0)
		return (write(1, "0", 1)); 
	digit = count_u_digit_base(16, unbr);
	hex = NULL;
	if (spec == 'x')
		hex = ft_itox(digit, unbr, "0123456789abcdef");
	else if (spec == 'X')
		hex = ft_itox(digit, unbr, "0123456789ABCDEF");
	ret = print_str_ap(hex);
	if (hex)
		free(hex);
	return (ret);
}