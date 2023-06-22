/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchernys <gchernys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 01:12:34 by gchernys          #+#    #+#             */
/*   Updated: 2023/06/21 14:20:23 by gchernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	basic_error_check(int argc, char **argv)
{
	char	*str;
	int		i;

	if (argc != 2)
	{
		write(2, "Error: Invalid number of arguments", 34);
		return (PARSE_ERR);
	}
	str = argv[1];
	i = ft_strlen(argv[1]);
	if (str[i - 1] != 'b' || str[i - 2] != 'u' || \
	str[i - 3] != 'c' || str[i - 4] != '.')
	{
		write(2, "Error: File needs to end with \".cub\" extension", 46);
		return (PARSE_ERR);
	}
	i = open(argv[1], O_RDONLY);
	if (i < 0)
	{
		write(2, "Couldn't open file", 18);
		return (PARSE_ERR);
	}
	close (i);
	return (0);
}

int	check_textures(t_map *map)
{
	set_textures(map);
	if (open(map->north, O_RDONLY) < 0)
		return (PARSE_ERR);
	close(open(map->north, O_RDONLY));
	if (open(map->south, O_RDONLY) < 0)
		return (PARSE_ERR);
	close(open(map->south, O_RDONLY));
	if (open(map->west, O_RDONLY) < 0)
		return (PARSE_ERR);
	close(open(map->west, O_RDONLY));
	if (open(map->east, O_RDONLY) < 0)
		return (PARSE_ERR);
	close(open(map->east, O_RDONLY));
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
		*dst++ = game->map->floor_color;
	i = game->win->window_w * game->win->window_h / 2;
	while (--i > 0)
		*dst++ = game->map->ceiling_color;
}
