/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smackere <smackere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 13:12:13 by smackere          #+#    #+#             */
/*   Updated: 2022/10/30 12:27:29 by smackere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	if (s[0] == (unsigned char)c)
		return ((char *)s);
	while (s[i] != '\0')
	{
		i++;
		if (s[i] == (unsigned char)c)
			return ((char *)(s + i));
	}
	return (NULL);
}
