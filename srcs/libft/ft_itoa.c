/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smackere <smackere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:55:44 by smackere          #+#    #+#             */
/*   Updated: 2022/10/29 05:08:45 by smackere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	bs_arr[12];
	int		i;
	int		neg;

	i = 10;
	if (n == 0)
		bs_arr[i--] = '0';
	neg = 1;
	if (n < 0)
		neg = -1;
	while (n != 0)
	{
		bs_arr[i] = neg * (n % 10) + '0';
		n /= 10;
		i--;
	}
	if (neg == -1)
		bs_arr[i--] = '-';
	while (i >= 0)
		bs_arr[i--] = ' ';
	bs_arr[11] = '\0';
	return (ft_strtrim(bs_arr, " "));
}
