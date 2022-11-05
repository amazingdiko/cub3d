/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_form.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smackere <smackere@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 05:15:30 by smackere          #+#    #+#             */
/*   Updated: 2022/11/01 15:14:09 by smackere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	ft_open_args(t_data *data, t_raycast *raycast)
{
	int		img_height;
	int		img_width;

	data->walls = (t_txtr *)malloc(sizeof(t_txtr));
	if (data->walls == NULL)
		ft_error(data, "malloc ft_open_args", 0);
	data->walls->north = mlx_xpm_file_to_image(raycast->mlx, data->nswe[0],
			&img_width, &img_height);
	data->walls->south = mlx_xpm_file_to_image(raycast->mlx, data->nswe[1],
			&img_width, &img_height);
	data->walls->west = mlx_xpm_file_to_image(raycast->mlx, data->nswe[2],
			&img_width, &img_height);
	data->walls->east = mlx_xpm_file_to_image(raycast->mlx, data->nswe[3],
			&img_width, &img_height);
	raycast->txt = data->walls;
	ft_memset(raycast->txt->buffer, 0, sizeof(int));
}

void	ft_destroy_images(t_data *data)
{
	mlx_destroy_image(data->raycast->mlx, data->walls->north);
	mlx_destroy_image(data->raycast->mlx, data->walls->south);
	mlx_destroy_image(data->raycast->mlx, data->walls->west);
	mlx_destroy_image(data->raycast->mlx, data->walls->east);
}
