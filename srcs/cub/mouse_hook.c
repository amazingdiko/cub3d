/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smackere <smackere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 13:55:09 by smackere          #+#    #+#             */
/*   Updated: 2022/10/28 00:15:47 by smackere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

static void	turn_mouse_left(t_raycast *raycast, double x)
{
	float		olddir_x;
	float		oldplane_x;

	olddir_x = raycast->dir_x;
	raycast->dir_x = raycast->dir_x * cos(-x)
		- raycast->dir_y * sin(-x);
	raycast->dir_y = olddir_x * sin(-x)
		+ raycast->dir_y * cos(-x);
	oldplane_x = raycast->plane_x;
	raycast->plane_x = raycast->plane_x * cos(-x)
		- raycast->plane_y * sin(-x);
	raycast->plane_y = oldplane_x * sin(-x)
		+ raycast->plane_y * cos(-x);
}

static void	turn_mouse_right(t_raycast *raycast, double x)
{
	float		olddir_x;
	float		oldplane_x;

	olddir_x = raycast->dir_x;
	raycast->dir_x = raycast->dir_x * cos(x)
		- raycast->dir_y * sin(x);
	raycast->dir_y = olddir_x * sin(x)
		+ raycast->dir_y * cos(x);
	oldplane_x = raycast->plane_x;
	raycast->plane_x = raycast->plane_x * cos(x)
		- raycast->plane_y * sin(x);
	raycast->plane_y = oldplane_x * sin(x)
		+ raycast->plane_y * cos(x);
}

int	mouse_hook(int x, int y, t_data *data)
{
	if (data->raycast->mouse_x == -1
		|| x < 0 || x > SCREENW || y < 0 || y > SCREENH)
	{
		data->raycast->mouse_x = x;
		data->raycast->mouse_y = y;
		return (0);
	}
	if (x < data->raycast->mouse_x)
		turn_mouse_left(data->raycast,
			(double)(data->raycast->mouse_x - x) / 360.0);
	else if (x > data->raycast->mouse_x)
		turn_mouse_right(data->raycast,
			(double)(x - data->raycast->mouse_x) / 360.0);
	data->raycast->mouse_x = x;
	data->raycast->mouse_y = y;
	return (0);
}
