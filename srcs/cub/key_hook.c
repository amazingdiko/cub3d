/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smackere <smackere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 04:18:33 by smackere          #+#    #+#             */
/*   Updated: 2022/10/27 04:11:33 by smackere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

static void	key_hook_move_w(t_raycast *raycast)
{
	if (raycast->main->map[(int)(raycast->pos_x + raycast->dir_x
			* (float)raycast->move_speed)][(int) raycast->pos_y] == '0'
			|| raycast->main->map[(int)(raycast->pos_x + raycast->dir_x
			* (float)raycast->move_speed)][(int) raycast->pos_y] == 'O')
		raycast->pos_x += raycast->dir_x * raycast->move_speed;
	if (raycast->main->map[(int)raycast->pos_x][(int)(raycast->pos_y
		+ raycast->dir_y * (float)raycast->move_speed)] == '0'
		|| raycast->main->map[(int)raycast->pos_x][(int)(raycast->pos_y
		+ raycast->dir_y * (float)raycast->move_speed)] == 'O')
		raycast->pos_y += raycast->dir_y * raycast->move_speed;
}

static void	key_hook_move_a(t_raycast *raycast)
{
	if (raycast->main->map[(int)raycast->pos_x][(int)raycast->pos_y
		- (int) raycast->plane_y * (int) raycast->move_speed] == '0'
		|| raycast->main->map[(int)raycast->pos_x][(int)raycast->pos_y
		- (int) raycast->plane_y * (int) raycast->move_speed] == 'O')
		raycast->pos_y -= raycast->plane_y * raycast->move_speed;
	if (raycast->main->map[(int)raycast->pos_x - (int) raycast->plane_x
			* (int) raycast->move_speed][(int)raycast->pos_y] == '0'
			|| raycast->main->map[(int)raycast->pos_x - (int) raycast->plane_x
			* (int) raycast->move_speed][(int)raycast->pos_y] == 'O')
		raycast->pos_x -= raycast->plane_x * raycast->move_speed;
}

static void	key_hook_move_d(t_raycast *raycast)
{
	if (raycast->main->map[(int)raycast->pos_x][(int)(raycast->pos_y
		+ raycast->plane_y * (float) raycast->move_speed)] == '0'
		|| raycast->main->map[(int)raycast->pos_x][(int)(raycast->pos_y
		+ raycast->plane_y * (float) raycast->move_speed)] == 'O')
		raycast->pos_y += raycast->plane_y * raycast->move_speed;
	if (raycast->main->map[(int)(raycast->pos_x + raycast->plane_x
			* (float)raycast->move_speed)][(int)(raycast->pos_y)] == '0'
			|| raycast->main->map[(int)(raycast->pos_x + raycast->plane_x
			* (float)raycast->move_speed)][(int)(raycast->pos_y)] == 'O')
		raycast->pos_x += raycast->plane_x * raycast->move_speed;
}

static void	key_hook_move_s(t_raycast *raycast)
{
	if (raycast->main->map[(int)(raycast->pos_x - raycast->dir_x
			* (float)raycast->move_speed)][(int) raycast->pos_y] == '0'
			|| raycast->main->map[(int)(raycast->pos_x - raycast->dir_x
			* (float)raycast->move_speed)][(int) raycast->pos_y] == 'O')
		raycast->pos_x -= raycast->dir_x * raycast->move_speed;
	if (raycast->main->map[(int)raycast->pos_x][(int)(raycast->pos_y
		- raycast->dir_y * (float)raycast->move_speed)] == '0'
		|| raycast->main->map[(int)raycast->pos_x][(int)(raycast->pos_y
		- raycast->dir_y * (float)raycast->move_speed)] == 'O')
		raycast->pos_y -= raycast->dir_y * raycast->move_speed;
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 53)
	{
		mlx_destroy_window(data->raycast->mlx, data->raycast->win);
		exit(0);
	}
	if (keycode == 49)
		key_hook_space(data);
	if (keycode == 13)
		key_hook_move_w(data->raycast);
	if (keycode == 1)
		key_hook_move_s(data->raycast);
	if (keycode == 124)
		key_hook_turn_r(data->raycast);
	if (keycode == 123)
		key_hook_turn_l(data->raycast);
	if (keycode == 0)
		key_hook_move_a(data->raycast);
	if (keycode == 2)
		key_hook_move_d(data->raycast);
	return (0);
}
