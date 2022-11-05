/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smackere <smackere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 00:33:59 by smackere          #+#    #+#             */
/*   Updated: 2022/10/29 17:11:39 by smackere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

static void	open_txt(t_data *main, t_textures *txt, char *path)
{
	txt->img_ptr = mlx_xpm_file_to_image(main->raycast->mlx,
			path, &txt->width, &txt->height);
	txt->img_data = mlx_get_data_addr(txt->img_ptr, &txt->bpp,
			&txt->line_len, &txt->endian);
}

static void	load_txt(t_data *main)
{
	open_txt(main, main->north, main->nswe[0]);
	open_txt(main, main->south, main->nswe[1]);
	open_txt(main, main->west, main->nswe[2]);
	open_txt(main, main->east, main->nswe[3]);
	if (main->nswe[4] != NULL)
		open_txt(main, main->doorc, main->nswe[4]);
	if (main->nswe[5] != NULL)
		open_txt(main, main->dooro, main->nswe[4]);
}

static void	init_txt(t_data *main)
{
	main->north = malloc(sizeof(t_textures));
	main->south = malloc(sizeof(t_textures));
	main->east = malloc(sizeof(t_textures));
	main->west = malloc(sizeof(t_textures));
	if (main->nswe[4] != NULL)
		main->doorc = malloc(sizeof(t_textures));
	if (main->nswe[5] != NULL)
		main->dooro = malloc(sizeof(t_textures));
	load_txt(main);
}

static void	init_st_rc2(t_data *main, t_raycast *raycast)
{
	if (main->playdir == 'N')
	{
		raycast->dir_x = 0;
		raycast->dir_y = -1;
	}
	if (main->playdir == 'S')
	{
		raycast->dir_x = 0;
		raycast->dir_y = 1;
	}
	if (main->playdir == 'E')
	{
		raycast->dir_x = 1;
		raycast->dir_y = 0;
	}
	if (main->playdir == 'W')
	{
		raycast->dir_x = -1;
		raycast->dir_y = 0;
	}
}

void	init_st_rc(t_data *main, t_raycast *raycast)
{
	raycast->pos_y = (double)main->player_base[0] + 0.5;
	raycast->pos_x = (double)main->player_base[1] + 0.5;
	raycast->main = main;
	raycast->camera_x = 0.0;
	raycast->move_speed = 0.1;
	raycast->rot_speed = 0.07;
	init_st_rc2(main, raycast);
	main->map[main->player_base[1]][main->player_base[0]] = '0';
	raycast->plane_x = -raycast->dir_y * 0.66;
	raycast->plane_y = raycast->dir_x * 0.66;
	raycast->side = 0;
	raycast->step = 0;
	ft_open_args(main, raycast);
	init_txt(main);
}
