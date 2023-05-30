/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_calc_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 17:08:51 by amalbrei          #+#    #+#             */
/*   Updated: 2023/05/30 13:10:19 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	cub_player_init(t_game **game)
{
	(*game)->player->fov = 60;
	(*game)->player->height = 32;
	if ((*game)->player->dir == 'N')
		(*game)->player->angle = 60;
	if ((*game)->player->dir == 'W')
		(*game)->player->angle = 150;
	if ((*game)->player->dir == 'S')
		(*game)->player->angle = 240;
	if ((*game)->player->dir == 'E')
		(*game)->player->angle = 330;
	(*game)->player->x_pos = (*game)->player->x * 64;
	(*game)->player->y_pos = (*game)->player->y * 64;
}

// int	cub_first_intersect(t_game **game, t_map *map, t_player *player)
// {
// 	int	verti_i;
// 	int	horiz_i;

// 	verti_i = cub_find_intersect(game, 'F', 'V');
// 	horiz_i = cub_find_intersect(game, 'F', 'H');
// 	if (horiz_i < verti_i && map->full_grid[player->y][player->x - 1] == '1')
// 	{
// 		(*game)->player->distance = horiz_i;
// 		return (1);
// 	}
// 	else if (verti_i < horiz_i
// 		&& map->full_grid[player->y - 1][player->x] == '1')
// 	{
// 		(*game)->player->distance = verti_i;
// 		return (1);
// 	}
// 	(*game)->player->verti_dis = verti_i;
// 	(*game)->player->horiz_dis = horiz_i;
// 	return (0);
// }

// void	cub_calc_player(t_game **game)
// {
// 	if (cub_first_intersect(game, (*game)->map), (*game)->player)
// 		// cub_draw_column(game);
// }
