/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitaliy <vitaliy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 15:38:04 by smackere          #+#    #+#             */
/*   Updated: 2022/11/01 17:14:23 by vitaliy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	ft_parse_map(t_data *data, int fd)
{
	int		gnl;
	int		l;

	ft_parse_params(data, &gnl, fd);
	ft_gnl_read(data, &gnl, fd, data->gnln);
	while (gnl != 0 && (*data->gnln)[0] == '\0')
		ft_gnl_read(data, &gnl, fd, data->gnln);
	while (gnl != 0)
	{
		l = ft_strlen(*data->gnln);
		if (l > data->width)
			data->width = l;
		if ((*data->gnln)[0] == '\0'
			|| ft_arr_plus_one(&(data->map), *data->gnln, 0, l) == NULL)
			ft_error(data, "map divided", 0);
		ft_gnl_read(data, &gnl, fd, data->gnln);
	}
	l = ft_strlen(*data->gnln);
	if (ft_arr_plus_one(&(data->map), *data->gnln, 0, l) == NULL)
		ft_error(data, "last string of map did't parsed", 0);
}

static void	ft_check_format(char *name)
{
	int	i;
	int	len;

	len = ft_strlen(name);
	if (len > 254)
		ft_error(NULL, "Invalid filename: too many characters", 0);
	i = 0;
	while (name[i] != '\0')
	{
		if (name[i] == '?' || name[i] == '<' || name[i] == '>'
			|| name[i] == '*' || name[i] == '"' || name[i] == '|')
			ft_error(NULL, "Invalid filename: illegal characters", 0);
		i++;
	}
	if (name[len - 4] != '.' || name[len - 3] != 'c' || name[len - 2] != 'u'
		|| name[len - 1] != 'b')
		ft_error(NULL, "Invalid format: file must have format \".cub\" ", 0);
}

void	check_argc_argv(int argc, char **argv)
{
	if (argc < 2)
		ft_error(NULL, "Too few arguments", 0);
	if (argc > 2)
		ft_error(NULL, "Too many arguments", 0);
	ft_check_format(argv[1]);
}

void	init_images(t_data *data)
{
	t_pixel		pixel;
	t_pixel		minimap;
	t_raycast	raycast;

	data->raycast = &raycast;
	raycast.mlx = mlx_init();
	init_st_rc(data, &raycast);
	raycast.pixel = &pixel;
	raycast.minimap = &minimap;
	raycast.win = mlx_new_window(raycast.mlx, SCREENW, SCREENH, "wmozella42");
	pixel.img = mlx_new_image(raycast.mlx, SCREENW, SCREENH);
	minimap.img = mlx_new_image(raycast.mlx, SCREENW / 6, SCREENH / 6);
	pixel.addr = mlx_get_data_addr(pixel.img, &pixel.bpp,
			&pixel.line_len, &pixel.endian);
	minimap.addr = mlx_get_data_addr(minimap.img,
			&minimap.bpp, &minimap.line_len, &minimap.endian);
	mlx_hook(raycast.win, 2, 0, key_hook, data);
	mlx_hook(raycast.win, 6, 0, mouse_hook, data);
	mlx_hook(raycast.win, 17, 0, ft_exit, NULL);
	mlx_loop_hook(raycast.mlx, ft_render, data);
	mlx_loop(raycast.mlx);
}

int	main(int argc, char *argv[])
{
	t_data		*data;
	int			fd;

	check_argc_argv(argc, argv);
	fd = ft_open(argv[1]);
	data = (t_data *)malloc(sizeof(t_data));
	if (data == NULL)
		ft_error(data, "Data initialization", 0);
	ft_bzero(data, sizeof(t_data));
	data->map = ft_calloc(1, sizeof(char *));
	if (data->map == NULL)
		ft_error(data, "ft_calloc for map", 0);
	ft_parse_map(data, fd);
	if (close(fd) == -1)
		ft_error(data, ft_itoa(fd), 1);
	data->high = ft_arrlen(data->map);
	ft_check_map(data);
	init_images(data);
	exit(EXIT_SUCCESS);
}
