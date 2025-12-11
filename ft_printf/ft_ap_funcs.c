/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ap_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heyu <heyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 21:36:54 by heychong          #+#    #+#             */
/*   Updated: 2025/12/08 17:13:03 by heyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char_ap(int c)
{
	return (write(1, &c, 1));
}

int	print_str_ap(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (write(1, str, len));
}

int	print_address_ap(void *ptr)
{
	unsigned int	tmp;
	unsigned int	digit;
	char			*str;

	tmp = (unsigned int)ptr;
	digit = count_hex_digit(tmp);
	str = ft_itox(digit, tmp, "0123456789abcdef");
	ret = print_str_ap(str);
	if (str)
		free(str);
	return (ret);
}

int	print_int_ap(int nbr)
{
	char	*str;
	int		ret;

	str = ft_itoa(nbr);
	ret = print_str_ap(str);
	if (str)
		free(str);
	return (ret);
}

int	print_uint_ap(unsigned int unbr)
{
	char	*str;
	int		ret;

	str = ft_utoa(unbr);
	ret = print_str_ap(str);
	if (str)
		free(str);
	return (ret);
}
