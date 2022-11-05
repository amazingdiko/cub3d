/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_cast.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smackere <smackere@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 23:07:55 by smackere          #+#    #+#             */
/*   Updated: 2022/11/01 15:15:10 by smackere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_CAST_H
# define CUB_CAST_H

//render.c
int		ft_render(t_data *data);

// mouse_hook.c
int		mouse_hook(int x, int y, t_data *data);

// init.c
void	init_st_rc(t_data *main, t_raycast *raycast);

// 
int		ft_exit(int x);
void	my_mlx_pixel_put(t_pixel *pixel, int x, int y, int color);
void	draw(t_data *data, t_textures *txt, int x);
void	draw_text(t_data *data, int x);

// key_hook.c
int		key_hook(int keycode, t_data *data);

// key_hook_help.c
void	key_hook_turn_l(t_raycast *raycast);
void	key_hook_turn_r(t_raycast *raycast);
void	key_hook_space(t_data *data);

// minimap.c
void	draw_minimap(t_data *data);

// minimap_all.c
void	draw_minimap_all(t_data *data, int ym, int i);

#endif
