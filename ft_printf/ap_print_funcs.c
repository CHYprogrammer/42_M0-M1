/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ap_print_funcs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heychong <heychong@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 21:36:54 by heychong          #+#    #+#             */
/*   Updated: 2025/12/02 21:55:22 by heychong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str_ap(char *str, va_list ap)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (write (1, str, len));
}

int	print_address_ap(void *ptr, va_list ap)
{
	return (1);
}

int	print_nbr_ap(int nbr, va_list ap)
{
	int		len;
	char	*str;

	str = ft_itoa(nbr);
	len = 0;
	while (str[len])
		len++;
	return (write(1, str, len));
}

int	print_unit_ap(unsigned int unit, va_list ap)
{
	int		len;
	char	*str;

	len = 0;
	str = ft_utoa(unit);
	while (str[len])
		len++;
	return (write(1, str, len));
}

int	print_nbr_base_ap(char digit, unsigned int hex, va_list ap);
