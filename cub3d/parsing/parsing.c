/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 01:12:34 by gchernys          #+#    #+#             */
/*   Updated: 2023/05/14 18:48:14 by amalbrei         ###   ########.fr       */
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
	if (map->north == NULL || map->south == NULL || map->west == NULL || \
	map->east == NULL || map->north[0] == '\0' || map->south[0] == '\0' || \
	map->west[0] == '\0' || map->east[0] == '\0')
		return (PARSE_ERR);
	return (0);
}
