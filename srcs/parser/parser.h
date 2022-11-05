/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smackere <smackere@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 01:15:45 by smackere          #+#    #+#             */
/*   Updated: 2022/11/01 15:14:19 by smackere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

void	ft_parse_params(t_data *data, int *gnl, int fd);
void	ft_parse_rgb(t_data *data, char ***tmp, int *op, int i);
void	ft_open_args(t_data *data, t_raycast *raycast);
void	ft_destroy_images(t_data *data);
void	ft_check_map(t_data *data);
char	**ft_dd_parse(char *str_map);
void	ft_map_data_form(char **map, t_data *data, int i);

#endif
