/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smackere <smackere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 01:09:21 by smackere          #+#    #+#             */
/*   Updated: 2022/10/24 21:55:52 by smackere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

static void	ft_to_width(t_data *data, int y, int ln, int tmpln)
{
	char	*tmp;
	char	*tmp2;

	if (data->map[y][ln - 1] == '\n')
		ln--;
	if (data->map[y][ln] == '\n')
		data->map[y][ln] = '\0';
	if (ln < data->width)
	{
		tmpln = data->width - ln;
		tmp2 = ft_strdup(data->map[y]);
		if (tmp2 == NULL)
			ft_error(data, "ft_to_width malloc", 0);
		tmp = ft_calloc(tmpln + 1, sizeof(char));
		if (tmp == NULL)
			ft_error(data, "ft_to_width malloc", 0);
		tmp = ft_memset(tmp, ' ', tmpln);
		free(data->map[y]);
		data->map[y] = ft_strjoin(tmp2, tmp);
		free(tmp);
		free(tmp2);
	}
}

static void	ft_check_core(t_data *data, char **m, int y, int x)
{
	while (m[y + 1] != NULL)
	{
		if (data->map[y] == NULL)
		{
			while (data->map[y + 1] != NULL)
			{
				free(data->map[y + 1]);
				y++;
			}
			ft_error(data, "malloc error ft_check_core", 0);
		}
		if ((m[y][0] != '1' && m[y][0] != ' ')
			|| (m[y][data->width - 1] != '1' && m[y][data->width - 1] != ' '))
			ft_error(data, "Frame is not full!", 0);
		x = 0;
		while (m[y][x + 1] != '\n' && m[y][x + 1] != '\0')
		{
			if ((m[y - 1][x] == ' ' || m[y + 1][x] == ' ' || m[y][x - 1] == ' '
				|| m[y][x + 1] == ' ') && m[y][x] != '1' && m[y][x] != ' ')
				ft_error(data, "Frame is not full!!", 0);
			x++;
		}
		y++;
	}
}

static void	ft_check_rectangularity_frame(t_data *data, char **map, int i)
{
	while (map[0][data->width] != '\n' && map[0][data->width] != '\0')
	{
		if (map[0][data->width] != '1' && map[0][data->width] != ' ')
			ft_error(data, "Frame is not full!!!", 0);
		data->width++;
	}
	if (data->map[1] != NULL)
	{
		ft_check_core(data, map, 1, 1);
		while (map[data->high - 1][i] != '\0')
		{
			if (map[data->high - 1][i] != '1' && map[data->high - 1][i] != ' ')
				ft_error(data, "Frame is not full!!!!!", 0);
			i++;
		}
	}
}

static int	ft_check_strangers_fullness(t_data *data, char *m, int j, int i)
{
	int	p;

	p = 0;
	while (m[i] != '\0')
	{
		if (m[i] != '0' && m[i] != 'C' && m[i] != 'O' && m[i] != '1'
			&& m[i] != 'N' && m[i] != 'S' && m[i] != 'E'
			&& m[i] != '\n' && m[i] != 'W' && m[i] != ' ')
		{
			m[i + 1] = '\0';
			ft_error(data, ft_strjoin("Illegal character ", &(m[i])), 0);
		}
		if (m[i] == 'S' || m[i] == 'N' || m[i] == 'W' || m[i] == 'E')
			p += ft_player_data(data, i, j);
		else if ((m[i] == 'C' && data->nswe[4] == NULL)
			|| (m[i] == 'O' && data->nswe[5] == NULL))
			ft_error(data, "Texture for one of doors doesn't exsist", 0);
		i++;
	}
	return (p);
}

void	ft_check_map(t_data *data)
{
	int	i;
	int	p;

	i = 0;
	p = 0;
	if (data->map == NULL)
		ft_error(data, "Map didn't parsed or file is empty", 0);
	while (data->map[i] != NULL)
	{
		p += ft_check_strangers_fullness(data, data->map[i], i, 0);
		i++;
	}
	if (p < 1)
		ft_error(data, "Where is starting character?", 0);
	if (p > 1)
		ft_error(data, "Too many starting characters", 0);
	i = 0;
	while (i < data->high)
	{
		ft_to_width(data, i, ft_strlen(data->map[i]), 0);
		i++;
	}
	ft_check_rectangularity_frame(data, data->map, 0);
	if (data->map[0][data->width] == '\n')
		data->map[0][data->width] = '\0';
}
