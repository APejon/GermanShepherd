/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 01:12:34 by gchernys          #+#    #+#             */
/*   Updated: 2023/06/27 18:44:50 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	basic_error_check(int argc, char **argv)
{
	char	*str;
	int		i;

	if (argc != 2)
	{
		write(2, "Error\n Invalid number of arguments", 34);
		exit(PARSE_ERR);
	}
	str = argv[1];
	i = ft_strlen(argv[1]);
	if (str[i - 1] != 'b' || str[i - 2] != 'u' || \
	str[i - 3] != 'c' || str[i - 4] != '.')
	{
		write(2, "Error\n File needs to end with \".cub\" extension\n", 47);
		exit(PARSE_ERR);
	}
	i = open(argv[1], O_RDONLY);
	if (i < 0)
	{
		write(2, "Error\n Couldn't open file", 25);
		exit(PARSE_ERR);
	}
	close (i);
	return (0);
}

static int	cub_check_file_extended(t_map *map, char *ext, int j, int i)
{
	j = -1;
	i = ft_find_char(map->east, '.');
	while (ext[++j] && map->east[++i])
	{
		if (map->east[i] != ext[j])
			return (1);
	}
	if (map->east[++i] != ext[j])
		return (1);
	j = -1;
	i = ft_find_char(map->west, '.');
	while (ext[++j] && map->west[++i])
	{
		if (map->west[i] != ext[j])
			return (1);
	}
	if (map->west[++i] != ext[j])
		return (1);
	return (0);
}

static int	cub_check_file_extensions(t_map *map, char *ext)
{
	int	j;
	int	i;

	j = -1;
	i = ft_find_char(map->north, '.');
	while (ext[++j] && map->north[++i])
	{
		if (map->north[i] != ext[j])
			return (1);
	}
	if (map->north[++i] != ext[j])
		return (1);
	j = -1;
	i = ft_find_char(map->south, '.');
	while (ext[++j] && map->south[++i])
	{
		if (map->south[i] != ext[j])
			return (1);
	}
	if (map->south[++i] != ext[j])
		return (1);
	if (cub_check_file_extended(map, ext, j, i))
		return (1);
	return (0);
}

int	check_textures(t_map *map)
{
	set_textures(map);
	if (cub_check_file_extensions(map, "xpm"))
		return (PARSE_ERR);
	if (map->north == NULL || map->south == NULL || map->west == NULL || \
	map->east == NULL || map->north[0] == '\0' || map->south[0] == '\0' || \
	map->west[0] == '\0' || map->east[0] == '\0')
		return (PARSE_ERR);
	return (0);
}

void	cub_draw_floor_and_ceiling(t_game *game)
{
	unsigned int	i;
	unsigned int	*dst;

	i = game->win->window_w * game->win->window_h / 2;
	dst = (unsigned int *) game->win->addr->ad;
	while (--i > 0)
		*dst++ = game->map->ceiling_color;
	i = game->win->window_w * game->win->window_h / 2;
	while (--i > 0)
		*dst++ = game->map->floor_color;
}
