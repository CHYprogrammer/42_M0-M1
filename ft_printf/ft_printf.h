/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heychong <heychong@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 12:46:25 by heyu              #+#    #+#             */
/*   Updated: 2025/12/27 23:53:45 by heychong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>
# include <stdint.h>

int	ft_printf(const char *format, ...);
int	printf_execute(va_list ap, const char *format);
int	print_ap(va_list ap, char spec);
int	print_char(char c);
int	print_str(char *str);
int	print_address(void *ptr);
int	print_nbr(int nbr);
int	print_uint(unsigned int unbr);
int	print_hex(unsigned int unbr, char spec);
size_t	count_digit(int nbr);
void	convertion_rec(int nbr, char *str, size_t *index);
char	*ft_itoa(int nbr);
int	ft_strlen(char *str);
size_t	count_u_digit_base(unsigned int unbr, int base);
char	*ft_itou_base(unsigned int unbr, char *base);

#endif
