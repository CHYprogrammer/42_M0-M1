/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heychong <heychong@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 12:46:25 by heyu              #+#    #+#             */
/*   Updated: 2026/01/18 21:29:34 by heychong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>

int		ft_printf(const char *format, ...);
int		ft_vprintf(const char *format, va_list ap);
int		handle_ap(va_list ap, char spec);
int		handle_c(int c);
int		handle_s(char *str);
int		handle_p(void *ptr);
int		handle_int(int nbr);
int		handle_u(char spec, unsigned long long unbr);
size_t	count_digit(int nbr);
void	convertion_rec(int nbr, char *str, size_t *index);
char	*ft_itoa(int nbr);
size_t	count_digit_base(unsigned long long unbr, int base);
char	*ft_itou_base(unsigned long long unbr, char *base);

#endif
