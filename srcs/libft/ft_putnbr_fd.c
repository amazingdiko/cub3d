/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smackere <smackere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 10:29:10 by smackere          #+#    #+#             */
/*   Updated: 2022/10/28 08:33:19 by smackere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n >= 0)
		n *= -1;
	else
		ft_putchar_fd('-', fd);
	if (n < -9)
	{
		ft_putnbr_fd((n / 10) * (-1), fd);
		ft_putnbr_fd((n % 10) * (-1), fd);
	}
	else
		ft_putchar_fd((n * (-1) + '0'), fd);
}
