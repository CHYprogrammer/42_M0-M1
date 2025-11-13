/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heychong <heychong@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 22:04:48 by heychong          #+#    #+#             */
/*   Updated: 2025/11/03 20:25:58 by heychong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	result;
	int	pos_neg;

	while ((*nptr >= 9 && *nptr <= 13) || *nptr == ' ')
		nptr++;
	pos_neg = 1;
	if (*nptr == '-')
	{
		pos_neg = -1;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	result = 0;
	while (ft_isdigit(*nptr))
	{
		result *= 10;
		result += *nptr - '0';
		nptr++;
	}
	result *= pos_neg;
	return (result);
}
