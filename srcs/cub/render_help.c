/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_help.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smackere <smackere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 20:49:51 by smackere          #+#    #+#             */
/*   Updated: 2022/10/27 02:37:35 by smackere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	ft_exit(int x)
{
	(void) x;
	exit(0);
}

void	my_mlx_pixel_put(t_pixel *pixel, int x, int y, int color)
{
	char	*dst;

	dst = pixel->addr + (y * pixel->line_len + x * (pixel->bpp / 8));
	*(unsigned int *)dst = color;
}

void	draw(t_data *data, t_textures *txt, int x)
{
	int		y;

	y = 0;
	while (y < data->raycast->draw_start)
	{
		my_mlx_pixel_put(data->raycast->pixel, x, y, data->ceilling);
		y++;
	}
	while (data->raycast->draw_start < data->raycast->draw_end)
	{
		data->raycast->tex_y = (int)data->raycast->tex_pos & (TEXH - 1);
		data->raycast->tex_pos += data->raycast->step;
		my_mlx_pixel_put(data->raycast->pixel, x, data->raycast->draw_start,
			get_pixel_color(txt, TEXW - data->raycast->tex_x - 1,
				data->raycast->tex_y));
		data->raycast->draw_start++;
	}
	while (data->raycast->draw_start < SCREENH)
	{
		my_mlx_pixel_put(data->raycast->pixel,
			x, data->raycast->draw_start, data->floor);
		data->raycast->draw_start++;
	}
}

void	draw_text(t_data *data, int x)
{
	t_textures	*txt;

	if (data->map[data->raycast->map_x][data->raycast->map_y] == '1'
		&& data->raycast->side == 0 && data->raycast->map_x
		> data->raycast->pos_x)
		txt = data->west;
	if (data->map[data->raycast->map_x][data->raycast->map_y] == '1'
		&& data->raycast->side == 0 && data->raycast->map_x
		<= data->raycast->pos_x)
		txt = data->east;
	if (data->map[data->raycast->map_x][data->raycast->map_y] == '1'
		&& data->raycast->side == 1 && data->raycast->map_y
		<= data->raycast->pos_y)
		txt = data->south;
	if (data->map[data->raycast->map_x][data->raycast->map_y] == '1'
		&& data->raycast->side == 1 && data->raycast->map_y
		> data->raycast->pos_y)
		txt = data->north;
	if (data->map[data->raycast->map_x][data->raycast->map_y] == 'C')
		txt = data->doorc;
	draw(data, txt, x);
}
