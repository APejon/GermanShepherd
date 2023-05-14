/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_and_colors.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 07:35:06 by gchernys          #+#    #+#             */
/*   Updated: 2023/05/14 18:48:21 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

unsigned long	setrgb(int red, int green, int blue)
{
	return (((red & 0xff) << 16) + ((green & 0xff) << 8) + (blue & 0xff));
}

int	check_rgb(char **str)
{
	int	i;
	int	j;

	j = 0;
	while (str[j])
	{
		i = 0;
		while (str[j][i])
		{
			if (!ft_isdigit(str[j][i]))
				return (PARSE_ERR);
			i++;
		}
		if (ft_strlen(str[j]) > 3 || ft_atoi(str[j]) > 255
			|| ft_atoi(str[j]) < 0)
			return (PARSE_ERR);
		j++;
	}
	if (j != 3)
		return (PARSE_ERR);
	return (0);
}

int	set_textures(t_map *map)
{
	int	j;
	int	i;
	int	k;

	j = -1;
	while (j++ < 6)
	{
		i = 0;
		while (ft_space(map->map[j][i]))
			i++;
		k = i + 2;
		if (ft_strncmp(map->map[j] + i, "NO", 2) == 0)
			map->north = ft_substr(map->map[j], k + spacecount(map->map[j], k), \
			ft_strlen(map->map[j]) - k - spacecount(map->map[j], k));
		else if (ft_strncmp(map->map[j] + i, "SO", 2) == 0)
			map->south = ft_substr(map->map[j], k + spacecount(map->map[j], k), \
			ft_strlen(map->map[j]) - k - spacecount(map->map[j], k));
		else if (ft_strncmp(map->map[j] + i, "WE", 2) == 0)
			map->west = ft_substr(map->map[j], k + spacecount(map->map[j], k), \
			ft_strlen(map->map[j]) - k - spacecount(map->map[j], k));
		else if (ft_strncmp(map->map[j] + i, "EA", 2) == 0)
			map->east = ft_substr(map->map[j], k + spacecount(map->map[j], k), \
			ft_strlen(map->map[j]) - k - spacecount(map->map[j], k));
	}
	return (0);
}

int	find_rgb(t_map *map)
{
	int	j;
	int	i;
	int	k;

	j = -1;
	while (j++ < 6)
	{
		i = 0;
		while (ft_space(map->map[j][i]))
			i++;
		k = i + 2;
		if (ft_strncmp(map->map[j] + i, "F ", 2) == 0)
			map->floor = ft_substr(map->map[j], k + spacecount(map->map[j], k), \
			ft_strlen(map->map[j]) - k - spacecount(map->map[j], k));
		else if (ft_strncmp(map->map[j] + i, "C ", 2) == 0)
			map->cil = ft_substr(map->map[j], k + spacecount(map->map[j], k), \
			ft_strlen(map->map[j]) - k - spacecount(map->map[j], k));
	}
	if (map->floor == NULL || map->cil == NULL || init_rgb(map) == PARSE_ERR)
		return (PARSE_ERR);
	return (0);
}

int	init_rgb(t_map *map)
{
	char			**temp;

	temp = ft_split(map->floor, ',');
	if (check_rgb(temp) == PARSE_ERR)
	{
		free_double_array(temp);
		return (PARSE_ERR);
	}
	if (ft_strlen(temp[0]) > 3 || ft_strlen(temp[1]) > 3 || \
		ft_strlen(temp[2]) > 3)
		return (PARSE_ERR);
	map->floor_color = setrgb(ft_atoi(temp[0]), ft_atoi(temp[1]), \
	ft_atoi(temp[2]));
	free_double_array(temp);
	temp = ft_split(map->cil, ',');
	if (check_rgb(temp) == PARSE_ERR)
	{
		free_double_array(temp);
		return (PARSE_ERR);
	}
	map->ceiling_color = setrgb(ft_atoi(temp[0]), ft_atoi(temp[1]), \
	ft_atoi(temp[2]));
	free_double_array(temp);
	printf("floor = %u, cil = %u\n", map->floor_color, map->ceiling_color);
	return (0);
}
