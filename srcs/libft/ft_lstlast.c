/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smackere <smackere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 17:46:56 by smackere          #+#    #+#             */
/*   Updated: 2022/10/24 18:22:24 by smackere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*ptr;
	int		i;

	if (!lst)
		return (NULL);
	ptr = lst;
	i = ft_lstsize(lst) - 1;
	while (i > 0)
	{
		ptr = ptr->next;
		i--;
	}
	return (ptr);
}
