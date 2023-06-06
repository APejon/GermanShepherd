/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_calc_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 17:08:51 by amalbrei          #+#    #+#             */
/*   Updated: 2023/06/06 15:12:46 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	cub_player_init(t_game **game)
{
	(*game)->player->fov = 60;
	(*game)->player->height = 32;
	if ((*game)->player->dir == 'N')
		(*game)->player->angle = 60.0;
	if ((*game)->player->dir == 'W')
		(*game)->player->angle = 150.0;
	if ((*game)->player->dir == 'S')
		(*game)->player->angle = 240.0;
	if ((*game)->player->dir == 'E')
		(*game)->player->angle = 330.0;
	(*game)->player->x_pos = ((*game)->player->x * (*game)->grid_size)
		+ ((*game)->grid_size / 2);
	(*game)->player->y_pos = ((*game)->player->y * (*game)->grid_size)
		+ ((*game)->grid_size / 2);
}

int	cub_subsequent_intersect(t_game **game, t_map *map, t_player *player)
{
	(void)map;
	cub_find_intersect(game, player, 's');
	printf("NEXT VERT %d and %d\n", (int)player->verti_i[0], (int)player->verti_i[1]);
	printf("NEXT HORIZ %d and %d\n", (int)player->horiz_i[0], (int)player->horiz_i[1]);
	return (0);
}

/**
 * @brief 
 * 
 * @param game 
 * @param map 
 * @param player 
 * @return int 
 * 
 * @note grid[1] is y, grid[0] is x
 */
int	cub_first_intersect(t_game **game, t_map *map, t_player *player)
{
	(void)game;
	(void)map;
	cub_find_intersect(game, player, 'f');
	printf("VERT %d and %d\n", (int)player->verti_i[0], (int)player->verti_i[1]);
	printf("HORIZ %d and %d\n", (int)player->horiz_i[0], (int)player->horiz_i[1]);
	// if (map->full_grid[(int)verti_i[0]][(int)verti_i[1]] == '1'
	// 	&& map->full_grid[(int)horiz_i[0]][(int)horiz_i[1]] == '1')
	// {
		
	// }
	// else if (map->full_grid[(int)verti_i[0]][(int)verti_i[1]] == '1')
	// {

	// }
	// else if (map->full_grid[(int)horiz_i[0]][(int)horiz_i[1]] == '1')
	// {
		
	// }
	// {
	// 	(*game)->player->distance = horiz_i;
	// 	return (1);
	// }
	// else if (verti_i < horiz_i
	// 	&& map->full_grid[player->y - 1][player->x] == '1')
	// {
	// 	(*game)->player->distance = verti_i;
	// 	return (1);
	// }
	return (0);
}

void	cub_calc_player(t_game **game)
{
	cub_prep_image(&((*game)->win));
	cub_first_intersect(game, (*game)->map, (*game)->player);
	// if (cub_first_intersect(game, (*game)->map, (*game)->player))
	// 	cub_draw_column(game);
	cub_subsequent_intersect(game, (*game)->map, (*game)->player);
	cub_place_image(&((*game)->win));
}
