/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smackere <smackere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 05:39:04 by smackere          #+#    #+#             */
/*   Updated: 2022/10/30 12:12:56 by smackere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

typedef struct s_pixel
{
	void			*img;
	char			*addr;
	int				bpp;
	int				line_len;
	int				endian;
}				t_pixel;

typedef struct s_textures
{
	void	*img_data;
	char	*img_ptr;
	int		*data;
	int		line_len;
	int		endian;
	int		width;
	int		height;
	int		bpp;
}	t_textures;

typedef struct s_raycast
{
	void			*mlx;
	void			*win;
	char			**m;
	int				size;
	int				side;
	float			step;
	float			pos_x;
	float			pos_y;
	float			dir_x;
	float			dir_y;
	float			plane_x;
	float			plane_y;
	double			move_speed;
	double			rot_speed;
	double			camera_x;
	float			raydir_x;
	float			raydir_y;
	float			sidedist_x;
	float			sidedist_y;
	float			deltadist_x;
	float			deltadist_y;
	float			perp_wall_dist;
	int				step_x;
	int				step_y;
	int				map_x;
	int				map_y;
	int				tex_x;
	float			tex_pos;
	int				tex_y;
	int				line_height;
	int				draw_start;
	int				draw_end;
	int				hit;
	int				mouse_x;
	int				mouse_y;
	float			wall_x;
	struct s_data	*main;
	t_pixel			*pixel;
	t_pixel			*minimap;
	t_textures		*txt_pxl;
	struct s_txtr	*txt;
}			t_raycast;

typedef struct s_txtr
{
	int			width;
	int			height;
	void		*north;
	void		*south;
	void		*west;
	void		*east;
	int			buffer[SCREENH][SCREENW];
}				t_txtr;

typedef struct s_data
{
	int			width;
	int			high;
	char		**map;
	char		*nswe[6];
	int			floor;
	int			ceilling;
	int			player_base[2];
	char		playdir;
	char		**gnln;
	t_textures	*north;
	t_textures	*south;
	t_textures	*west;
	t_textures	*east;
	t_textures	*doorc;
	t_textures	*dooro;
	t_txtr		*walls;
	t_raycast	*raycast;
}				t_data;

#endif
