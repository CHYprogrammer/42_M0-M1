/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heychong <heychong@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 12:42:48 by heyu              #+#    #+#             */
/*   Updated: 2026/01/18 20:33:24 by heychong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_ap(va_list ap, char spec)
{
	if (!spec)
		return (-1);
	if (spec == 'c')
		return (handle_c(va_arg(ap, int)));
	else if (spec == 's')
		return (handle_s(va_arg(ap, char *)));
	else if (spec == 'p')
		return (handle_p(va_arg(ap, void *)));
	else if (spec == 'd' || spec == 'i')
		return (handle_int(va_arg(ap, int)));
	else if (spec == 'u')
		return (handle_u(spec, va_arg(ap, unsigned int)));
	else if (spec == 'x')
		return (handle_u(spec, va_arg(ap, unsigned int)));
	else if (spec == 'X')
		return (handle_u(spec, va_arg(ap, unsigned int)));
	else if (spec == '%')
		return (write(1, "%", 1));
	return (0);
}

int	ft_vprintf(const char *format, va_list ap)
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
			ap_len = handle_ap(ap, format[i + 1]);
			if (ap_len < 0)
				return (-1);
			len = len + ap_len;
			i = i + 2;
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

	if (!format)
		return (-1);
	va_start(ap, format);
	len = ft_vprintf(format, ap);
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
