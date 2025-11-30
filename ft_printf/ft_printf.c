/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heychong <heychong@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 12:42:48 by heyu              #+#    #+#             */
/*   Updated: 2025/11/30 19:33:55 by heychong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	print_error(char *error_message)
{
	write(2, error_message, ft_strlen(error_message));
	return (1);
}

int	ft_printf(const char *format, ...)
{
	char	*find;
	char	*str;
	char	*trimmed;
	size_t	len;
	char	error_message[128];

	if (!format)
		return (1);
	error_message = "error";
	find = ft_strdup(ft_strchr(format, '%'));
	trimmed = ft_strdup(ft_strtrim(format, find));
	if (trimmed)
		write(1, trimmed, ft_strlen(trimmed));
	if (find)
	{
		va_start()
		if (find[1] == 'c')

		else if (find[1] == 's')
		else if (find[1] == 'p')
		else if (find[1] == 'd')
		else if (find[1] == 'i')
		else if (find[1] == 'u')
		else if (find[1] == 'x')
		else if (find[1] == 'X')
		else if (find[1] == '%')
			write(1, "%%", 1);
		else
			print_error("wrong format");
	}
	else
		write(1, format, len);
}
