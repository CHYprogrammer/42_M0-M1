/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_ap_funcs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heychong <heychong@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 21:35:31 by heychong          #+#    #+#             */
/*   Updated: 2026/01/18 21:42:32 by heychong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_c(int c)
{
	return (write(1, &c, 1));
}

int	handle_s(char *str)
{
	int	len;

	if (!str)
		return (write(1, "(null)", 6));
	len = 0;
	while (str[len])
		len++;
	return (write(1, str, len));
}

int	handle_p(void *ptr)
{
	int	ret;

	if (!ptr)
		return (write(1, "(nil)", 5));
	ret = write(1, "0x", 2);
	ret += handle_u('x', (uintptr_t)ptr);
	return (ret);
}

int	handle_int(int nbr)
{
	char	*str;
	int		ret;

	str = ft_itoa(nbr);
	if (!str)
		return (-1);
	ret = handle_s(str);
	free(str);
	return (ret);
}

int	handle_u(char spec, unsigned long long unbr)
{
	char	*str;
	int		ret;

	str = NULL;
	if (spec == 'u')
		str = ft_itou_base(unbr, "0123456789");
	else if (spec == 'x')
		str = ft_itou_base(unbr, "0123456789abcdef");
	else if (spec == 'X')
		str = ft_itou_base(unbr, "0123456789ABCDEF");
	if (!str)
		return (-1);
	ret = handle_s(str);
	free(str);
	return (ret);
}
