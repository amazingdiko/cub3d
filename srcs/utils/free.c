/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smackere <smackere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 02:35:48 by smackere          #+#    #+#             */
/*   Updated: 2022/10/28 07:50:02 by smackere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

char	**ft_free_arr(char **arr, int ln)
{
	int	i;

	if (arr != NULL)
	{
		i = 0;
		while (i < ln)
		{
			if (arr[i] != NULL)
			{
				ft_bzero(arr[i], ft_strlen(arr[i]));
				free(arr[i]);
			}
			i++;
		}
		ft_bzero(arr, sizeof(char *));
		free(arr);
	}
	return (NULL);
}

void	ft_free_data(t_data *data)
{
	int	i;

	if (data != NULL)
	{
		if (data->map != NULL)
			ft_free_arr(data->map, ft_arrlen(data->map));
		i = 0;
		while (i < 6)
		{
			if (data->nswe[i] != NULL)
				free(data->nswe[i]);
			i++;
		}
		ft_bzero(data->nswe, sizeof(char *) * 6);
		if (data->gnln != NULL)
		{
			if (*data->gnln != NULL)
				free(*data->gnln);
			free(data->gnln);
		}
		ft_bzero(data, sizeof(t_data));
		free(data);
	}
}

void	ft_context_free_err(t_data *data, char ***tmp, int aln, char *msg)
{
	ft_free_arr(*tmp, aln);
	free(tmp);
	ft_error(data, msg, 0);
}
