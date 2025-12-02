/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heychong <heychong@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 12:46:25 by heyu              #+#    #+#             */
/*   Updated: 2025/12/02 21:44:04 by heychong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <limits.h>

typedef struct s_args
{
	int				c;
	char			*s;
	void			*p;
	int				n;
	unsigned int	u;
	unsigned int	x;
}	t_args;

#endif
