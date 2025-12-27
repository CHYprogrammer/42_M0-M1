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
	return (write(1, "%", 1) + write(1, &spec, 1));
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
			if (!format[i + 1])
				return (-1);
			i++;
			ap_len = print_ap(ap, format[i]);
			if (ap_len < 0)
				return (-1);
			len += ap_len;
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

	if (!format)
		return (-1);
	va_start(ap, format);
	len = printf_execute(ap, format);
	va_end(ap);
	return (len);
}

size_t	count_digit(int nbr)
{
	size_t	digit;

	digit = 0;
	if (nbr <= 0)
		digit++;
	while (nbr)
	{
		digit++;
		nbr /= 10;
	}
	return (digit);
}

void	convertion_rec(int nbr, char *str, size_t *index)
{
	if (nbr / 10)
		convertion_rec(nbr / 10, str, index);
	if (nbr < 0)
		str[*index] = '0' - (nbr % 10);
	else
		str[*index] = '0' + (nbr % 10);
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

size_t	count_u_digit_base(unsigned int base, unsigned int unbr)
{
	size_t	digit;

	if (!unbr)
		return (1);
	digit = 0;
	while (unbr)
	{
		digit++;
		unbr /= base;
	}
	return (digit);
}

char	*ft_utoa(unsigned int unbr)
{
	char	*str;
	size_t	digit;
	size_t	i;

	if (unbr == 0)
		return (ft_strdup("0"));
	digit = count_u_digit_base(10, unbr);
	str = malloc(digit + 1);
	if (!str)
		return (NULL);
	i = digit;
	while (i--)
	{
		str[i] = '0' + (unbr % 10);
		unbr /= 10;
	}
	str[digit] = '\0';
	return (str);
}

int	print_char_ap(int c)
{
	return (write(1, &c, 1));
}

int	print_str_ap(char *str)
{
	int	len;

	if (!str)
		return (write(1, "(null)", 6));
	len = 0;
	while (str[len])
		len++;
	return (write(1, str, len));
}

int	print_address_ap(void *ptr)
{
	uintptr_t	value;
	char		*str;
	int			ret;

	if (!ptr)
		return (write(1, "(nil)", 5));
	value = (uintptr_t)ptr;
	str = ft_itox(count_digit_base(16, value), value, "0123456789abcdef");
	ret = print_str_ap("0x");
	ret += print_str_ap(str);
	free(str);
	return (ret);
}

int	print_int_ap(int nbr)
{
	char	*str;
	int		ret;

	str = ft_itoa(nbr);
	ret = print_str_ap(str);
	free(str);
	return (ret);
}

int	print_uint_ap(unsigned int unbr)
{
	char	*str;
	int		ret;

	str = ft_utoa(unbr);
	ret = print_str_ap(str);
	free(str);
	return (ret);
}

char	*ft_itox(unsigned int digit, unsigned int unbr, char *base)
{
	char			*hex;
	unsigned int	i;

	hex = malloc(digit + 2 + 1);
	if (!hex)
		return (NULL);
	i = 1;
	hex[0] = '0';
	hex[1] = 'x';
	while (unbr)
	{
		hex[digit - i + 2] = base[unbr % 16];
		unbr /= 16;
		i++;
	}
	hex[digit + 2] = '\0';
	return (hex);
}

int	print_hex_ap(char spec, unsigned int unbr)
{
	unsigned int	digit;
	char			*hex;
	int				ret;

	if (unbr == 0)
		return (write(1, "0", 1));
	digit = count_u_digit_base(16, unbr);
	hex = NULL;
	if (spec == 'x')
		hex = ft_itox(digit, unbr, "0123456789abcdef");
	else if (spec == 'X')
		hex = ft_itox(digit, unbr, "0123456789ABCDEF");
	ret = print_str_ap(hex);
	if (hex)
		free(hex);
	return (ret);
}