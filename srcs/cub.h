/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smackere <smackere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 10:08:57 by smackere          #+#    #+#             */
/*   Updated: 2022/10/28 23:13:02 by smackere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# define SCREENW 1920
# define SCREENH 1440
# define TEXW 512
# define TEXH 512
# include "../mlx/mlx.h"
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <math.h>
# include "libft/libft.h"
# include "gnl/get_next_line.h"
# include "types.h"
# include "parser/parser.h"
# include "cub/cub_cast.h"

//Функции общего назначения (utils.c)
void	ft_error(t_data *data, char *msg, int op);
int		ft_open(char *flnm);
void	ft_gnl_read(t_data *data, int *gnl, int fd, char **ln);
void	pixel_put(t_pixel *pixel, int x, int y, int color);
// int		pixel_get(t_textures *txt, int x, int y);
int		get_pixel_color(t_textures *txt, int x, int y);
int		ft_player_data(t_data *data, int i, int j);
// void	pixel_put(t_raycast *raycast, int x, int y, int color);

//Функции для работы с массивом
char	**ft_arr_plus_one(char ***sub_arr, char *str, int i, int ln);
void	ft_putarr_fd(char **arr, int fd);
int		ft_arrlen(char **arr);
char	**ft_arrdup(char **arr);
char	**ft_arrjoin(char **arr1, char **arr2);

//Очистка памяти (free.c)
void	ft_context_free_err(t_data *data, char ***tmp, int aln, char *msg);
void	ft_free_data(t_data *data);
char	**ft_free_arr(char **arr, int ln);

// cub
int		dolznoBitVmain(t_data *main, t_raycast *raycast);

#endif
