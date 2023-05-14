/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 01:29:17 by gchernys          #+#    #+#             */
/*   Updated: 2023/05/14 18:54:10 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_double_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	return_error(char *str, t_map *map, t_game *game)
{
	if (map->map)
		free_double_array(map->map);
	if (map->north)
		free(map->north);
	if (map->south)
		free(map->south);
	if (map->west)
		free(map->west);
	if (map->east)
		free(map->east);
	if (map->floor)
		free(map->floor);
	if (map->cil)
		free(map->cil);
	free(map->player);
	free(map);
	free(game);
	ft_putstr_fd(str, 2);
	exit(1);
}
