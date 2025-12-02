/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heychong <heychong@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 12:42:48 by heyu              #+#    #+#             */
/*   Updated: 2025/12/02 21:35:09 by heychong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	end_func(va_list ap)
{
	va_end(ap);
	return (-1);
}

int	print_ap(va_list ap, char spec)
{
	t_args	arg;

	if (spec == 'c')
	{
		arg.c = va_arg(ap, char);
		return (write(1, &arg.c, 1));
	}
	else if (spec == 's')
		return (print_str_ap(args.s, ap));
	else if (spec == 'p')
		return (print_address_ap(arg.p, ap));
	else if (spec == 'd' || spec == 'i')
		return (print_nbr_ap(arg.n, ap));
	else if (spec == 'u')
		return (print_unit_ap(arg.u, ap));
	else if (spec == 'x')
		return (print_nbr_base_ap("0123456789abcdef", arg.x, ap));
	else if (spec == 'X')
		return (print_nbr_base_ap("0123456789ABCDEF", arg.x, ap));
	else if (spec == '%')
		return (write(1, "%%", 1));
	else
		return (-1);
}

int	ft_printf(const char *format, ...)
{
	size_t	i;
	size_t	len;
	va_list	ap;
	char	format_len;
	char	spec;

	va_start(ap, format);
	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			spec = format[i + 1];
			format_len = print_ap(ap, spec);
			if (format_len < 0)
				return (end_func(ap));
			len += format_len;
			i += 2;
			continue ;
		}
		if (write(1, &format[i], 1) == -1)
			return (-1);
		len++;
		i++;
	}
	va_end(ap);
	return (len);
}
