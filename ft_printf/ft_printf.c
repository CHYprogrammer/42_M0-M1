/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heyu <heyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 12:42:48 by heyu              #+#    #+#             */
/*   Updated: 2025/12/01 15:09:23 by heyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	print_error(char *error_message)
{
	write(2, error_message, ft_strlen(error_message));
	return (-1);
}

int	print_format(const char *var_str, ...);


int	ft_printf(const char *format, ...)
{
	size_t	i;
	size_t	len;
	char	*var_str;
	char	format_len;

	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			format_len = printf_format(var_str, ...);
			if (format_len < 0)
				return (print_error("wrong format"));
			else
				len += format_len;
			i += 2;
			continue ;
		}
		if (write(1, &format[i], 1) == -1)
			return (-1);
		len++;
		i++;
	}
	return (len);
}
