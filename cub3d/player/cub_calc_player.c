/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_calc_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 17:08:51 by amalbrei          #+#    #+#             */
/*   Updated: 2023/06/06 18:55:33 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	cub_player_init(t_game **game)
{
	cub_find_player(game, (*game)->map);
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

double	cub_get_distance(t_player *player, double *dest)
{
	return (sqrt((dest[0] - player->x_pos) * (dest[0] - player->x_pos)
			+ (dest[1] - player->y_pos) * (dest[1] - player->y_pos)));
}

int	cub_subsequent_intersect(t_game **game, t_map *m, t_player *play)
{
	cub_find_intersect(game, play, 's');
	printf("NEXT VERT %d and %d\n", (int)play->verti_i[0], (int)play->verti_i[1]);
	printf("NEXT HORIZ %d and %d\n", (int)play->horiz_i[0], (int)play->horiz_i[1]);
	if (m->full_grid[(int)play->verti_i[1]][(int)play->verti_i[0]] == '1'
		&& m->full_grid[(int)play->horiz_i[1]][(int)play->horiz_i[0]] == '1')
	{
		(*game)->player->verti_dis = cub_get_distance(play, play->verti_i);
		(*game)->player->horiz_dis = cub_get_distance(play, play->horiz_i);
		return (1);
	}
	else if (m->full_grid[(int)play->verti_i[1]][(int)play->verti_i[0]] == '1')
	{
		(*game)->player->verti_dis = cub_get_distance(play, play->verti_i);
		return (1);
	}
	else if (m->full_grid[(int)play->horiz_i[1]][(int)play->horiz_i[0]] == '1')
	{
		(*game)->player->horiz_dis = cub_get_distance(play, play->horiz_i);
		return (1);
	}
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
int	cub_first_intersect(t_game **game, t_map *m, t_player *play)
{
	cub_find_intersect(game, play, 'f');
	printf("VERT %d and %d\n", (int)play->verti_i[0], (int)play->verti_i[1]);
	printf("HORIZ %d and %d\n", (int)play->horiz_i[0], (int)play->horiz_i[1]);
	if (m->full_grid[(int)play->verti_i[1]][(int)play->verti_i[0]] == '1'
		&& m->full_grid[(int)play->horiz_i[1]][(int)play->horiz_i[0]] == '1')
	{
		(*game)->player->verti_dis = cub_get_distance(play, play->verti_i);
		(*game)->player->horiz_dis = cub_get_distance(play, play->horiz_i);
		return (1);
	}
	else if (m->full_grid[(int)play->verti_i[1]][(int)play->verti_i[0]] == '1')
	{
		(*game)->player->verti_dis = cub_get_distance(play, play->verti_i);
		return (1);
	}
	else if (m->full_grid[(int)play->horiz_i[1]][(int)play->horiz_i[0]] == '1')
	{
		(*game)->player->horiz_dis = cub_get_distance(play, play->horiz_i);
		return (1);
	}
	return (0);
}

void	cub_calc_player(t_game **game)
{
	cub_prep_image(&((*game)->win));
	if (cub_first_intersect(game, (*game)->map, (*game)->player))
		printf("found you\n");
		// cub_draw_column(game);
	else
	{
		while (1)
		{
			if (cub_subsequent_intersect(game, (*game)->map, (*game)->player))
			{
				printf("%f AND %f\n", (*game)->player->horiz_dis, (*game)->player->verti_dis);
				printf("found it\n");
				break ;
			}
			printf("looking...\n");
		}
		// cub_draw_column(game);
	}
	cub_place_image(&((*game)->win));
}
