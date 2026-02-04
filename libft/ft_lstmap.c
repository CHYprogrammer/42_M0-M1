/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heychong <heychong@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 18:35:17 by heychong          #+#    #+#             */
/*   Updated: 2026/02/04 21:20:03 by heychong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*next;

	if (!lst || !f || !del)
		return (NULL);
	new = ft_lstnew(lst->content);
	if (!new)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
		new = new->next;
	}
	while (new->next)
	{
		next = new->next;
		new->content = f(new->content);
		if (!new->content)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		new = next;
	}
	return (new);
}