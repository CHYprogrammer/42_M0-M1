/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heychong <heychong@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 12:42:48 by heyu              #+#    #+#             */
/*   Updated: 2025/12/24 15:48:30 by heychong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_ap(va_list ap, char spec)
{
	if (!spec)
		return (-1);
	if (spec == 'c')
		return (print_char_ap(va_arg(ap, int)));
	else if (spec == 's')
		return (print_str_ap(va_arg(ap, char *)));
	else if (spec == 'p')
		return (print_address_ap(va_arg(ap, void *)));
	else if (spec == 'd' || spec == 'i')
		return (print_int_ap(va_arg(ap, int)));
	else if (spec == 'u')
		return (print_uint_ap(va_arg(ap, unsigned int)));
	else if (spec == 'x')
		return (print_hex_ap(spec, va_arg(ap, unsigned int)));
	else if (spec == 'X')
		return (print_hex_ap(spec, va_arg(ap, unsigned int)));
	else if (spec == '%')
		return (write(1, "%", 1));
	else
		return (-1);
}

int	printf_execute(va_list ap, const char *format)
{
	int	i;
	int	len;
	int	ap_len;

	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			ap_len = print_ap(ap, format[i + 1]);
			if (ap_len < 0)
				return (-1);
			len += ap_len - 1;
			i++;
			continue ;
		}
		if (write(1, &format[i], 1) == -1)
			return (-1);
		len++;
		i++;
	}
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		len;

	va_start(ap, format);
	len = printf_execute(ap, format);
	va_end(ap);
	return (len);
}

//int	main(void)
//{
//	char			c = 'a';
//	char			*s = "Hi, guy";
//	void			*p = &c;
//	int				d = INT_MIN;
//	int				i = INT_MAX;
//	unsigned int	u = 42;

//	ft_printf("char: %c, str: %s.\nYour addres: %p\n", c, s, p);
//	ft_printf("your number: %d & %i\n and", d, i);
//	ft_printf("your achieved the goal of %u%%\n", u);
//}
