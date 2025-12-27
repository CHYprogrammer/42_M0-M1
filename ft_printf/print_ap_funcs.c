/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ap_funcs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heychong <heychong@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 21:35:31 by heychong          #+#    #+#             */
/*   Updated: 2025/12/28 00:15:34 by heychong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(char c)
{
	return (write(1, &c, 1));
}

int	print_str(char *str)
{
	if (!str)
		return (write(1, "(null)", 6));
	return (write(1, str, ft_strlen(str)));
}

int	print_address(void *ptr)
{
	int	ret;

	if (!ptr)
		return (write(1, "(nil)", 5));
	ret = write(1, "0x", 2);
	ret += print_hex((uintptr_t)ptr, 'x');
	return (ret);
}

int	print_nbr(int nbr)
{
	return (print_str(ft_itoa(nbr)));
}

int	print_uint(unsigned int unbr)
{
	return (print_str(ft_itou_base(unbr, "0123456789")));
}

int	print_hex(unsigned int unbr, char spec)
{
	char	*base;

	base = NULL;
	if (spec == 'x')
		base = "0123456789abcdef";
	else if (spec == 'X')
		base = "0123456789ABCDEF";
	return (print_str(ft_itou_base(unbr, base)));
}

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

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

size_t	count_u_digit_base(unsigned int unbr, int base)
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

char	*ft_itou_base(unsigned int unbr, char *base)
{
	char	*str;
	size_t	digit;
	size_t	index;
	unsigned int	base_len;

	base_len = ft_strlen(base);
	digit = count_u_digit_base(unbr, base_len);
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