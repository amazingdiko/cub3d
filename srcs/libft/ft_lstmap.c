/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smackere <smackere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 02:50:49 by smackere          #+#    #+#             */
/*   Updated: 2022/10/29 08:22:47 by smackere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newls;
	t_list	*page;

	if (!lst)
		return (NULL);
	newls = ft_lstnew(f(lst->content));
	if (!newls)
	{
		ft_lstdelone(newls, del);
		return (NULL);
	}
	while (lst->next != NULL)
	{
		lst = lst->next;
		page = ft_lstnew(f(lst->content));
		if (!page)
		{
			ft_lstclear(&newls, del);
			return (NULL);
		}
		ft_lstadd_back(&newls, page);
	}
	return (newls);
}
