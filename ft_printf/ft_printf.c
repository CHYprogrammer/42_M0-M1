/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heychong <heychong@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 12:42:48 by heyu              #+#    #+#             */
/*   Updated: 2025/12/02 16:32:22 by heychong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	print_error(char *error_message)
{
	write(2, error_message, ft_strlen(error_message));
	return (-1);
}

int	print_var(va_list var_str, char	*specifier)
{
	int	ret;

	if (specifier == 'c')
		ret = write(1, &arg, 1);
	else if (specifier == 's')
		ret = ft_putstr_ret(var);
	else if (specifier == 'p')
		ret = ft_putaddress_ret(var);
	else if (specifier == 'd')
		ret = ft_putnbr_ret(var);
	else if (specifier == 'i')
		ret = ft_putnbr_ret(var);
	else if (specifier == 'u')
	{
		if (var_str < 0)
			return (-1);
		ret = ft_putnbr_ret(var);
	}
	else if (specifier == 'x')
		ret = ft_putnbr_base_ret(var, "0123456789abcdef");
	else if (specifier == 'X')
		ret = ft_putnbr_base_ret(var, "0123456789ABCDEF");
	else if (specifier == '%')
		ret = write(1, "%%", 1);
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	size_t	i;
	size_t	len;
	va_list	var;
	char	format_len;
	char	specifier;

	i = 0;
	len = 0;
	va_start(var, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			specifier = format[i + 1];
			format_len = printf_var(specifier, var);
			if (format_len < 0)
				return (print_error("wrong format"));
			else
				len += format_len;
			i += 2;
			var.content = var.next;
			continue ;
		}
		if (write(1, &format[i], 1) == -1)
			return (-1);
		len++;
		i++;
	}
	va_end(var);
	return (len);
}
