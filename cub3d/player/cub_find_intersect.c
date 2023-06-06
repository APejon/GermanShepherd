/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_find_intersect.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 21:08:36 by amalbrei          #+#    #+#             */
/*   Updated: 2023/06/06 16:00:21 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	cub_find_next_h(t_game **game, t_player *player)
{
	if (player->angle == 0 || player->angle == 180)
		return ;
	else if (player->angle > 0 && player->angle < 180)
	{
		(*game)->player->horiz_i[1] -= 64;
		(*game)->player->horiz_i[0] += 64 / tan(player->angle
				* (M_PI / 180));
	}
	else if (player->angle > 180 && player->angle < 360)
	{
		(*game)->player->horiz_i[1] += 64;
		(*game)->player->horiz_i[0] -= 64 / tan(player->angle
				* (M_PI / 180));
	}
}

void	cub_find_next_v(t_game **game, t_player *player)
{
	if (player->angle == 90 || player->angle == 270)
		return ;
	else if (player->angle > 270 || player->angle < 90)
	{
		(*game)->player->verti_i[0] += (*game)->grid_size;
		(*game)->player->verti_i[1] -= (*game)->grid_size
			* tan(player->angle * (M_PI / 180));
	}
	else if (player->angle > 90 && player->angle < 270)
	{
		(*game)->player->verti_i[0] -= (*game)->grid_size;
		(*game)->player->verti_i[1] += (*game)->grid_size
			* tan(player->angle * (M_PI / 180));
	}
}

void	cub_find_first_h(t_game **game, t_player *player)
{
	if (player->angle == 0 || player->angle == 180)
	{
		(*game)->player->horiz_i[1] = -1;
		(*game)->player->horiz_i[0] = -1;
	}
	else if (player->angle > 0 && player->angle < 180)
	{
		(*game)->player->horiz_i[1] = floor(player->y_pos / 64) * 64 - 1;
		(*game)->player->horiz_i[0] = player->x_pos + (player->y_pos
				- player->horiz_i[1]) / tan(player->angle * (M_PI / 180.0));
	}
	else if (player->angle > 180 && player->angle < 360)
	{
		(*game)->player->horiz_i[1] = floor(player->y_pos / 64) * 64 + 64;
		(*game)->player->horiz_i[0] = player->x_pos + (player->y_pos
				- player->horiz_i[1]) / tan(player->angle * (M_PI / 180.0));
	}
}

void	cub_find_first_v(t_game **game, t_player *player)
{
	if (player->angle == 90 || player->angle == 270)
	{
		(*game)->player->verti_i[0] = -1;
		(*game)->player->verti_i[1] = -1;
	}
	else if (player->angle > 270 || player->angle < 90)
	{
		(*game)->player->verti_i[0] = floor(player->x_pos / 64) * 64 + 64;
		(*game)->player->verti_i[1] = player->y_pos + (player->x_pos
				- player->verti_i[0]) * tan(player->angle * (M_PI / 180.0));
	}
	else if (player->angle > 90 && player->angle < 270)
	{
		(*game)->player->verti_i[0] = floor(player->x_pos / 64) * 64 - 1;
		(*game)->player->verti_i[1] = player->y_pos + (player->x_pos
				- player->verti_i[0]) * tan(player->angle * (M_PI / 180.0));
	}
}

/**
 * @brief 
 * 
 * @param player 
 * @param strt_flag 
 * @param dir_flag 
 * @return int* 
 * 
 * @note grid[1] is y, grid[0] is x
 */
void	cub_find_intersect(t_game **game, t_player *player, char strt_flag)
{
	if (strt_flag == 'f')
	{
		cub_find_first_v(game, player);
		cub_find_first_h(game, player);
		if (player->horiz_i[0] == 0)
			(*game)->player->horiz_i[0] = player->x_pos;
		cub_grid_division(game, player);
	}
	else if (strt_flag == 's')
	{
		cub_grid_mult(game, player);
		cub_find_next_v(game, player);
		cub_find_next_h(game, player);
		cub_grid_division(game, player);
	}
}
