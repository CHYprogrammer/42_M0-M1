/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heychong <heychong@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 17:28:25 by heychong          #+#    #+#             */
/*   Updated: 2025/10/27 22:31:52 by heychong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int	n, int	fd)
{
	ft_putstr_fd(ft_itoa(n), fd);
}

int	main()
{
	ft_putnbr_fd(-1, 1);
}
