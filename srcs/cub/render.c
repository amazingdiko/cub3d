/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smackere <smackere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 23:54:23 by smackere          #+#    #+#             */
/*   Updated: 2022/10/30 11:06:12 by smackere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	calc_wall_draw(t_data *data)
{
	data->raycast->line_height = (int)(SCREENH / data->raycast->perp_wall_dist);
	data->raycast->draw_start = -data->raycast->line_height / 2 + SCREENH / 2;
	if (data->raycast->draw_start < 0)
		data->raycast->draw_start = 0;
	data->raycast->draw_end = data->raycast->line_height / 2 + SCREENH / 2;
	if (data->raycast->draw_end >= SCREENH)
		data->raycast->draw_end = SCREENH - 1;
	if (data->raycast->side == 0)
		data->raycast->wall_x = data->raycast->pos_y
			+ data->raycast->perp_wall_dist * data->raycast->raydir_y;
	else
		data->raycast->wall_x = data->raycast->pos_x
			+ data->raycast->perp_wall_dist * data->raycast->raydir_x;
	data->raycast->wall_x -= floorf((data->raycast->wall_x));
	data->raycast->tex_x = (int)(data->raycast->wall_x * (float)TEXW);
	if (data->raycast->side == 0 && data->raycast->raydir_x > 0)
		data->raycast->tex_x = TEXW - data->raycast->tex_x - 1;
	if (data->raycast->side == 1 && data->raycast->raydir_y < 0)
		data->raycast->tex_x = TEXW - data->raycast->tex_x - 1;
	data->raycast->step = 1.0f * TEXH / data->raycast->line_height;
	data->raycast->tex_pos = (data->raycast->draw_start - SCREENH / 2
			+ data->raycast->line_height / 2) * data->raycast->step;
}

void	calc_dist(t_data *data)
{
	data->raycast->hit = 0;
	while (data->raycast->hit == 0)
	{
		if (data->raycast->sidedist_x < data->raycast->sidedist_y)
		{
			data->raycast->sidedist_x += data->raycast->deltadist_x;
			data->raycast->map_x += data->raycast->step_x;
			data->raycast->side = 0;
		}
		else
		{
			data->raycast->sidedist_y += data->raycast->deltadist_y;
			data->raycast->map_y += data->raycast->step_y;
			data->raycast->side = 1;
		}
		if (data->map[data->raycast->map_x][data->raycast->map_y] == '1'
			|| data->map[data->raycast->map_x][data->raycast->map_y] == 'C')
			data->raycast->hit = 1;
	}
	if (data->raycast->side == 0)
		data->raycast->perp_wall_dist = data->raycast->sidedist_x
			- data->raycast->deltadist_x;
	else
		data->raycast->perp_wall_dist = data->raycast->sidedist_y
			- data->raycast->deltadist_y;
}

void	select_steps(t_data *data)
{
	if (data->raycast->raydir_x < 0)
	{
		data->raycast->step_x = -1;
		data->raycast->sidedist_x = (data->raycast->pos_x
				- data->raycast->map_x) * data->raycast->deltadist_x;
	}
	else
	{
		data->raycast->step_x = 1;
		data->raycast->sidedist_x = (data->raycast->map_x + 1.0
				- data->raycast->pos_x) * data->raycast->deltadist_x;
	}
	if (data->raycast->raydir_y < 0)
	{
		data->raycast->step_y = -1;
		data->raycast->sidedist_y = (data->raycast->pos_y
				- data->raycast->map_y) * data->raycast->deltadist_y;
	}
	else
	{
		data->raycast->step_y = 1;
		data->raycast->sidedist_y = (data->raycast->map_y + 1.0
				- data->raycast->pos_y) * data->raycast->deltadist_y;
	}
}

static void	calc_dirs(t_data *data, int x)
{
	data->raycast->camera_x = 2 * x / (float) SCREENW - 1;
	data->raycast->raydir_x = data->raycast->dir_x
		+ data->raycast->plane_x * data->raycast->camera_x;
	data->raycast->raydir_y = data->raycast->dir_y
		+ data->raycast->plane_y * data->raycast->camera_x;
	data->raycast->map_x = (int) data->raycast->pos_x;
	data->raycast->map_y = (int) data->raycast->pos_y;
	data->raycast->deltadist_x = fabs(1 / data->raycast->raydir_x);
	data->raycast->deltadist_y = fabs(1 / data->raycast->raydir_y);
}

int	ft_render(t_data *data)
{
	int			x;

	x = 0;
	mlx_clear_window(data->raycast->mlx, data->raycast->win);
	while (x < SCREENW)
	{
		calc_dirs(data, x);
		select_steps(data);
		calc_dist(data);
		calc_wall_draw(data);
		draw_text(data, x);
		x++;
	}
	draw_minimap(data);
	mlx_put_image_to_window(data->raycast->mlx,
		data->raycast->win, data->raycast->pixel->img, 0, 0);
	mlx_put_image_to_window(data->raycast->mlx,
		data->raycast->win, data->raycast->minimap->img, 100, 100);
	return (0);
}
