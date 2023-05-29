/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchernys <gchernys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 01:16:27 by gchernys          #+#    #+#             */
/*   Updated: 2023/05/29 09:21:58 by gchernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	set_dimensions(t_map *map, char *file)
{
	char	*temp;
	int		fd;

	fd = open(file, O_RDONLY);
	temp = get_next_line(fd);
	if (!temp)
		return (MALLOC_ERR);
	while (temp != NULL)
	{
		if (ft_strlen(temp) > map->wide)
			map->wide = ft_strlen(temp);
		if (ft_strcmp(temp, "\n") != 0)
			map->high++;
		free(temp);
		if (map->high > 6 && ft_strcmp(temp, "\n") == 0)
		{
			close(fd);
			return (MALLOC_ERR);
		}
		temp = get_next_line(fd);
	}
	free(temp);
	close(fd);
	return (0);
}

void	setmap(char **tempmap, t_map *map)
{
	size_t	j;
	size_t	i;

	j = 0;
	while (tempmap[j] != NULL)
	{
		i = 0;
		ft_strlcpy(map->map[j], tempmap[j], map->wide + 1);
		while (i < map->wide && j > 5)
		{
			if (ft_strchr(" \t", map->map[j][i]))
				map->map[j][i] = 'x';
			i++;
			if (i == map->wide)
				map->map[j][i] = '\0';
		}
		j++;
	}
	map->map[j] = NULL;
}

int	malloc_map(t_map *map, char *file)
{
	size_t	i;

	if (set_dimensions(map, file))
		return (MALLOC_ERR);
	i = 0;
	map->map = malloc(sizeof(char *) * (map->high + 1));
	if (map->map == NULL)
		return (MALLOC_ERR);
	while (i < map->high)
	{
		map->map[i] = malloc(sizeof(char) * (map->wide + 2));
		ft_bzero(map->map[i], map->wide + 2);
		if (map->map[i] == NULL)
			return (MALLOC_ERR);
		i++;
	}
	map->player = malloc(sizeof(t_player));
	return (0);
}

int	load_map(t_game *game, t_map *map, char *file)
{
	int		fd;
	char	*temp;
	char	*str;
	char	**map_temp;

	str = NULL;
	fd = open(file, O_RDONLY);
	temp = get_next_line(fd);
	while (temp != NULL)
	{
		str = ft_strjoin_gnl(str, temp);
		free(temp);
		temp = get_next_line(fd);
	}
	free(temp);
	close(fd);
	map_temp = ft_split(str, '\n');
	free(str);
	setmap(map_temp, map);
	free_double_array(map_temp);
	validate_map(map, game);
	return (0);
}

int	validate_map(t_map *map, t_game *game)
{
	if (map->high < 6)
		return_error("Error\n map's too short\n\n", map, game);
	else if (find_rgb(map) == PARSE_ERR)
		return_error("Error\n Invalid RGB\n\n", map, game);
	else if (validate_vertices(map->map, map) == PARSE_ERR)
		return_error("Error\n Invalid vertices in map\n\n", map, game);
	else if (check_textures(map) == PARSE_ERR)
		return_error("Error\n Invalid textures\n\n", map, game);
	else if (validate_sides(map->map) == PARSE_ERR)
		return_error("Error\n Invalid sides in map\n\n", map, game);
	else if (validate_space(map->map) == PARSE_ERR)
		return_error("Error\n 0 or Player touching a space\n\n", map, game);
	else if (validate_player_count(map->map) == PARSE_ERR)
		return_error("Error\n Invalid Players and/or symbols\n\n", map, game);
	printf("%s\n", map->north);
	return (0);
}
