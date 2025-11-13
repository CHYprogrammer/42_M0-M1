/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heychong <heychong@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 18:24:19 by heychong          #+#    #+#             */
/*   Updated: 2025/10/28 19:27:31 by heychong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *input)
{
	t_list	*res;

	res = malloc(sizeof(void *) + sizeof(t_list *));
	res->content = input;
	res->next = NULL;
	return (res);
}

/*int	main()
{
	int	a = 1;
	ft_lstnew(&a);
}*/
