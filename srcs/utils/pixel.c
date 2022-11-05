/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smackere <smackere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 19:59:28 by smackere          #+#    #+#             */
/*   Updated: 2022/10/26 11:51:59 by smackere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

// void	pixel_put(t_raycast *raycast, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = raycast->addr + (y * raycast->line_len + x * (raycast->bpp / 8));
// 	*(unsigned int*)dst = color;
// }

void	pixel_put(t_pixel *pixel, int x, int y, int color)
{
	char	*dst;

	dst = pixel->addr + (y * pixel->line_len + x * (pixel->bpp / 8));
	*(unsigned int *)dst = color;
}

// int	pixel_get(t_textures *txt, int x, int y)
// {
// 	char	*ptr;

// 	ptr = txt->img_data + (y * txt->line_len + x * (txt->bpp / 8));
// 	return (*(int *)ptr);
// }
int	get_pixel_color(t_textures *txt, int x, int y)
{
	int	color;

	color = *(unsigned int *)(txt->img_data + (y * txt->line_len
				+ x * (txt->bpp / 8)));
	return (color);
}
