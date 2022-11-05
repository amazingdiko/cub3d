/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smackere <smackere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:59:00 by smackere          #+#    #+#             */
/*   Updated: 2022/10/28 10:35:04 by smackere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isupper_bonus(int c)
{
	if (c >= 65 && c <= 90)
		return (1);
	return (0);
}

static int	ft_islower_bonus(int c)
{
	if (c >= 97 && c <= 122)
		return (1);
	return (0);
}

int	ft_isalpha(int c)
{
	if (ft_isupper_bonus(c) || ft_islower_bonus(c))
		return (1);
	return (0);
}
