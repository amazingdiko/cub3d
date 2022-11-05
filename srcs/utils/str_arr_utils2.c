/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_arr_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smackere <smackere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 16:50:27 by smackere          #+#    #+#             */
/*   Updated: 2022/10/30 12:05:59 by smackere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

static char	**ft_strtoarr(char *str)
{
	char	**arr;

	arr = malloc(sizeof(char *) * 2);
	if (arr == NULL)
		return (NULL);
	arr[0] = ft_strdup(str);
	if (arr[0] == NULL)
		return (ft_free_arr(arr, 0));
	arr[1] = NULL;
	return (arr);
}

char	**ft_arr_plus_one(char ***sub_arr, char *str, int i, int ln)
{
	char	**tmp;
	char	**tmp2;
	char	*substr;

	if (ln <= 0)
		return (*sub_arr);
	tmp = ft_arrdup(*sub_arr);
	ft_free_arr(*sub_arr, ft_arrlen(*sub_arr));
	if (tmp == NULL)
		return (NULL);
	substr = ft_substr(str, i, ln);
	if (substr == NULL)
		return (ft_free_arr(tmp, ft_arrlen(tmp)));
	tmp2 = ft_strtoarr(substr);
	free(substr);
	if (tmp2 == NULL)
		return (ft_free_arr(tmp, ft_arrlen(tmp)));
	(*sub_arr) = ft_arrjoin(tmp, tmp2);
	ft_free_arr(tmp, ft_arrlen(tmp));
	ft_free_arr(tmp2, ft_arrlen(tmp2));
	if (*sub_arr == NULL)
		return (NULL);
	return (*sub_arr);
}
