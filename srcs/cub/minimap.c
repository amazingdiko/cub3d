/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smackere <smackere@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:08:54 by smackere          #+#    #+#             */
/*   Updated: 2022/11/01 15:15:39 by smackere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

static void	draw_minimap_door_other(t_data *data, int ym, int xm)
{
	int		yp;
	int		ys;
	int		xp;
	int		xs;

	yp = ym + 8;
	ys = ym;
	while (ys < yp)
	{
		xp = xm + 8;
		xs = xm;
		while (xs < xp)
		{
			my_mlx_pixel_put(data->raycast->minimap, xs, ys, 0x99433f3f);
			xs++;
		}
		ys++;
	}
}

static void	draw_phone(t_data *data)
{
	int		ym;
	int		xm;

	ym = 0;
	while (ym < SCREENH / 6)
	{
		xm = 0;
		while (xm < SCREENW / 6)
		{
			draw_minimap_door_other(data, ym, xm);
			xm += 8;
		}
		ym += 8;
	}
}

void	draw_minimap(t_data *data)
{
	int		ym;
	int		i;

	draw_phone(data);
	ym = 0;
	i = 0;
	draw_minimap_all(data, ym, i);
}
