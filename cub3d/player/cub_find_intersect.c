/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_find_intersect.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 21:08:36 by amalbrei          #+#    #+#             */
/*   Updated: 2023/06/15 17:20:07 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	cub_find_next_h(t_game **game, t_player *player)
{
	cub_grid_mult_hori(game, player);
	if (player->r_angle == 0.0 || player->r_angle == 180.0)
	{
		(*game)->player->horiz_i[1] = -1.0;
		(*game)->player->horiz_i[0] = -1.0;
	}
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
	cub_grid_div_hori(game, player);
}

void	cub_find_next_v(t_game **game, t_player *player)
{
	cub_grid_mult_verti(game, player);
	if (player->r_angle == 90.0 || player->r_angle == 270.0)
	{
		(*game)->player->verti_i[0] = -1.0;
		(*game)->player->verti_i[1] = -1.0;
	}
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
	cub_grid_div_verti(game, player);
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
	cub_grid_div_hori(game, player);
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
	cub_grid_div_verti(game, player);
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
char	cub_find_intersect(t_game **game, t_map *m, t_player *pl,
			char strt_flag)
{
	if (strt_flag == 'f')
	{
		cub_find_first_v(game, pl);
		cub_find_first_h(game, pl);
		if (pl->horiz_i[0] == 0.0)
			(*game)->player->horiz_i[0] = pl->x_pos;
		// if (pl->r_angle <= pl->p_angle + 30 && pl->r_angle >= pl->p_angle + 25)
		// {
		// 	printf("ANGLE: %f === ", pl->r_angle);
		// 	printf("TAN: %f\n", tan(pl->r_angle * (M_PI / 180)));
		// 	printf("FIRST VERTI: %d and %d === ", (int)pl->verti_i[1], (int)pl->verti_i[0]);
		// 	printf("FIRST HORIZ: %d and %d === \n", (int)pl->horiz_i[1], (int)pl->horiz_i[0]);
		// }
	}
	else if (strt_flag == 's')
	{
		// printf("%f\n", pl->r_angle);
		// printf("%c FLAG\n", pl->prot_flag);
		// printf("%d and %d\n", (int)pl->verti_i[1], (int)pl->verti_i[0]);
		if (pl->prot_flag != 'v')
		{
			if (m->full_grid[(int)pl->verti_i[1]][(int)pl->verti_i[0]]
				!= '1')
				cub_find_next_v(game, pl);
		}
		if (pl->prot_flag != 'h')
		{
			if (m->full_grid[(int)pl->horiz_i[1]][(int)pl->horiz_i[0]]
				!= '1')
				cub_find_next_h(game, pl);
			if (pl->horiz_i[0] == 0.0)
				(*game)->player->horiz_i[0] = pl->x_pos;
		}
		// if (pl->r_angle <= pl->p_angle + 30 && pl->r_angle >= pl->p_angle + 25)
		// {
		// 	printf("NEXT VERTI: %d and %d === ", (int)pl->verti_i[1], (int)pl->verti_i[0]);
		// 	printf("NEXT HORIZ: %d and %d === \n", (int)pl->horiz_i[1], (int)pl->horiz_i[0]);
		// }
	}
	if (pl->verti_i[0] < 0.0 || pl->verti_i[1] < 0.0
		|| pl->verti_i[0] >= m->wide || pl->verti_i[1] >= m->high)
	{
		(*game)->player->verti_i[0] = -1;
		(*game)->player->verti_i[1] = -1;
		return ('v');
	}
	if (pl->horiz_i[0] < 0.0 || pl->horiz_i[1] < 0.0
		|| pl->horiz_i[0] >= m->wide || pl->horiz_i[1] >= m->high)
	{
		(*game)->player->horiz_i[0] = -1;
		(*game)->player->horiz_i[1] = -1;
		return ('h');
	}
	return ('n');
}
