/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smackere <smackere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:59:32 by smackere          #+#    #+#             */
/*   Updated: 2022/10/29 00:32:52 by smackere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	void	*d;

	d = b;
	i = 0;
	while (i < len)
	{
		*(unsigned char *)(d + i) = (unsigned char)c;
		i++;
	}
	return (d);
}
