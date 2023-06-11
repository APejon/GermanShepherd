/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_find_intersect.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 21:08:36 by amalbrei          #+#    #+#             */
/*   Updated: 2023/06/11 16:41:58 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	cub_find_next_h(t_game **game, t_player *player)
{
	if (player->r_angle == 0.0 || player->r_angle == 180.0)
		return ;
	else if (player->r_angle > 0.0 && player->r_angle < 180.0)
	{
		(*game)->player->horiz_i[1] -= ((double)(*game)->grid_size);
		(*game)->player->horiz_i[0] += ((double)(*game)->grid_size)
			/ tan(player->r_angle * (M_PI / 180.0));
	}
	else if (player->r_angle > 180.0 && player->r_angle < 360.0)
	{
		(*game)->player->horiz_i[1] += ((double)(*game)->grid_size);
		(*game)->player->horiz_i[0] -= ((double)(*game)->grid_size)
			/ tan(player->r_angle * (M_PI / 180.0));
	}
}

void	cub_find_next_v(t_game **game, t_player *player)
{
	if (player->r_angle == 90.0 || player->r_angle == 270.0)
		return ;
	else if (player->r_angle > 270.0 || player->r_angle < 90.0)
	{
		(*game)->player->verti_i[0] += ((double)(*game)->grid_size);
		(*game)->player->verti_i[1] -= ((double)(*game)->grid_size)
			* tan(player->r_angle * (M_PI / 180.0));
	}
	else if (player->r_angle > 90.0 && player->r_angle < 270.0)
	{
		(*game)->player->verti_i[0] -= ((double)(*game)->grid_size);
		(*game)->player->verti_i[1] += ((double)(*game)->grid_size)
			* tan(player->r_angle * (M_PI / 180.0));
	}
}

void	cub_find_first_h(t_game **game, t_player *player)
{
	if (player->r_angle == 0.0 || player->r_angle == 180.0)
	{
		(*game)->player->horiz_i[1] = -1.0;
		(*game)->player->horiz_i[0] = -1.0;
	}
	else if (player->r_angle > 0.0 && player->r_angle < 180.0)
	{
		(*game)->player->horiz_i[1] = floor(player->y_pos / 64.0) * 64.0 - 1.0;
		(*game)->player->horiz_i[0] = player->x_pos + (player->y_pos
				- player->horiz_i[1]) / tan(player->r_angle * (M_PI / 180.0));
	}
	else if (player->r_angle > 180.0 && player->r_angle < 360.0)
	{
		(*game)->player->horiz_i[1] = floor(player->y_pos / 64.0) * 64.0 + 64.0;
		(*game)->player->horiz_i[0] = player->x_pos + (player->y_pos
				- player->horiz_i[1]) / tan(player->r_angle * (M_PI / 180.0));
	}
}

void	cub_find_first_v(t_game **game, t_player *player)
{
	if (player->r_angle == 90.0 || player->r_angle == 270.0)
	{
		(*game)->player->verti_i[0] = -1.0;
		(*game)->player->verti_i[1] = -1.0;
	}
	else if (player->r_angle > 270.0 || player->r_angle < 90.0)
	{
		(*game)->player->verti_i[0] = floor(player->x_pos / 64.0) * 64.0 + 64.0;
		(*game)->player->verti_i[1] = player->y_pos + (player->x_pos
				- player->verti_i[0]) * tan(player->r_angle * (M_PI / 180.0));
	}
	else if (player->r_angle > 90.0 && player->r_angle < 270.0)
	{
		(*game)->player->verti_i[0] = floor(player->x_pos / 64.0) * 64.0 - 1.0;
		(*game)->player->verti_i[1] = player->y_pos + (player->x_pos
				- player->verti_i[0]) * tan(player->r_angle * (M_PI / 180.0));
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
char	cub_find_intersect(t_game **game, t_player *player, char strt_flag)
{
	if (strt_flag == 'f')
	{
		cub_find_first_v(game, player);
		cub_find_first_h(game, player);
		if (player->horiz_i[0] == 0.0)
			(*game)->player->horiz_i[0] = player->x_pos;
		cub_grid_div_verti(game, player);
		cub_grid_div_hori(game, player);
	}
	else if (strt_flag == 's')
	{
		cub_grid_mult_verti(game, player);
		cub_grid_mult_hori(game, player);
		cub_find_next_v(game, player);
		cub_find_next_h(game, player);
		cub_grid_div_verti(game, player);
		cub_grid_div_hori(game, player);
	}
	if (player->verti_i[0] < 0.0 || player->verti_i[1] < 0.0)
		return ('v');
	if (player->horiz_i[0] < 0.0 || player->horiz_i[1] < 0.0)
		return ('h');
	return ('n');
}
