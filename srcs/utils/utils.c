/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smackere <smackere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 07:52:16 by smackere          #+#    #+#             */
/*   Updated: 2022/10/27 09:37:35 by smackere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	ft_error_fd(t_data *data, char *msg, int op, int fd)
{
	if (close(fd) == -1)
		ft_error(data, "е**ть", 0);
	ft_error(data, msg, op);
}

void	ft_error(t_data *data, char *msg, int op)
{
	ft_putstr_fd("Error\n", 2);
	if (op == 0)
		ft_putstr_fd(msg, 2);
	if (op == 1)
		perror(msg);
	ft_free_data(data);
	exit(EXIT_FAILURE);
}

int	ft_open(char *flnm)
{
	int	fd;

	fd = open(flnm, O_RDONLY);
	if (fd == -1)
		ft_error(NULL, flnm, 1);
	return (fd);
}

void	ft_gnl_read(t_data *data, int *gnl, int fd, char **ln)
{
	if (*ln != NULL)
	{
		free(*ln);
		*gnl = ft_get_next_line(fd, ln);
		if (*gnl == -1)
		{
			*ln = NULL;
			if (close(fd) == -1)
				ft_error(data, "GNL and close", 0);
			ft_error(data, "GNL", 0);
		}
	}
}

int	ft_player_data(t_data *data, int i, int j)
{
	data->playdir = data->map[j][i];
	data->player_base[0] = i;
	data->player_base[1] = j;
	return (1);
}
