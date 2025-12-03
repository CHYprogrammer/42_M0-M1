/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heyu <heyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 12:46:25 by heyu              #+#    #+#             */
/*   Updated: 2025/12/03 20:31:56 by heyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>

int		print_ap(va_list ap, char spec);
int		print_char_ap(int c);
int		print_str_ap(char *str);
int		print_address_ap(void *ptr);
int		print_int_ap(int nbr);
int		print_uint_ap(unsigned int unbr);
int		print_hex_ap(char spec, unsigned int unbr);
char	*ft_itoa(int nbr);
char	*ft_utoa(unsigned int unbr);

#endif
