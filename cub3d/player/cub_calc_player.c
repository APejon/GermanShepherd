/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_calc_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 17:08:51 by amalbrei          #+#    #+#             */
/*   Updated: 2023/06/11 17:17:16 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

double	cub_get_distance(t_player *player, double *dest)
{
	return (sqrt((dest[0] - player->x_pos) * (dest[0] - player->x_pos)
			+ (dest[1] - player->y_pos) * (dest[1] - player->y_pos)));
}

int	cub_subsequent_intersect(t_game **game, t_map *m, t_player *play)
{
	char	flag;
	char	r_flag;

	(*game)->player->verti_dis = INT_MAX;
	(*game)->player->horiz_dis = INT_MAX;
	flag = cub_find_intersect(game, play, 's');
	if (flag != 'v')
	{
		if (m->full_grid[(int)play->verti_i[1]][(int)play->verti_i[0]] == '1')
		{
			cub_grid_mult_verti(game, play);
			(*game)->player->verti_dis = cub_get_distance(play, play->verti_i);
			r_flag = 'r';
		}
	}
	if (flag != 'h')
	{
		if (m->full_grid[(int)play->horiz_i[1]][(int)play->horiz_i[0]] == '1')
		{
			cub_grid_mult_hori(game, play);
			(*game)->player->horiz_dis = cub_get_distance(play, play->horiz_i);
			r_flag = 'r';
		}
	}
	if (r_flag == 'r')
		return (1);
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
	char	flag;
	char	r_flag;

	flag = cub_find_intersect(game, play, 'f');
	if (flag != 'v')
	{
		if (m->full_grid[(int)play->verti_i[1]][(int)play->verti_i[0]] == '1')
		{
			cub_grid_mult_verti(game, play);
			(*game)->player->verti_dis = cub_get_distance(play, play->verti_i);
			r_flag = 'r';
		}
	}
	if (flag != 'h')
	{
		if (m->full_grid[(int)play->horiz_i[1]][(int)play->horiz_i[0]] == '1')
		{
			cub_grid_mult_hori(game, play);
			(*game)->player->horiz_dis = cub_get_distance(play, play->horiz_i);
			r_flag = 'r';
		}
	}
	if (r_flag == 'r')
		return (1);
	return (0);
}

void	cub_calc_player(t_game **game, t_player *player, t_window *win)
{
	double	x;

	x = 0.0;
	cub_prep_image(*game, &((*game)->win), 'g');
	while (x <= player->fov)
	{
		if (cub_first_intersect(game, (*game)->map, (*game)->player))
			cub_draw_column(game, (*game)->map, player, win);
		else
		{
			while (1)
			{
				if (cub_subsequent_intersect(game, (*game)->map,
						(*game)->player))
					break ;
			}
			cub_draw_column(game, (*game)->map, player, win);
		}
		(*game)->player->r_angle -= (double)player->fov / (double)win->window_w;
		if (player->r_angle < 0)
			(*game)->player->r_angle = 360 - player->fov / win->window_w;
		x += (double)player->fov / (double)win->window_w;
	}
	cub_place_image(&((*game)->win));
}
