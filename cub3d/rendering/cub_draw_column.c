/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_draw_column.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 14:00:33 by amalbrei          #+#    #+#             */
/*   Updated: 2023/06/11 18:11:23 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	cub_put_column(t_game *game, int draw_start, int draw_end)
{
	int	y;

	y = 0;
	if (game->player->side == NORTH)
		game->color = 0x013220;
	else if (game->player->side == EAST)
		game->color = 0x32CD32;
	if (game->win_x <= game->m_width)
	{
		while (y <= game->m_height)
			y++;
	}
	while (y < draw_start)
		y++;
	while (y >= draw_start && y <= draw_end && y <= game->win->window_h)
	{
		my_mlx_pixel_put(game, game->win_x, y);
		y++;
	}
	game->win_x++;
}

void	cub_prep_column(t_game *game, t_map *map, t_player *player,
						t_window *win)
{
	int	wall_height;
	int	draw_start;
	int	draw_end;

	(void)map;
	wall_height = (int)ceil(game->grid_size / player->correct_dis
			* player->project_dis);
	draw_start = (win->window_h / 2) - (wall_height / 2);
	if (draw_start < 0)
		draw_start = 0;
	draw_end = (win->window_h / 2) + (wall_height / 2);
	if (draw_end > win->window_h)
		draw_end = win->window_h;
	cub_put_column(game, draw_start, draw_end);
}

void	cub_correct_distance(t_game **game, t_player *player)
{
	if (player->p_angle < 30)
	{
		if (player->r_angle < 60)
			(*game)->player->correct_dis *= cos((player->r_angle
						- player->p_angle) * (M_PI / 180));
		else if (player->r_angle >= 330)
			(*game)->player->correct_dis *= cos(((player->r_angle - 360)
						- player->p_angle) * (M_PI / 180));
	}
	else if (player->p_angle >= 330)
	{
		if (player->r_angle < 60)
			(*game)->player->correct_dis *= cos(((player->r_angle + 360)
						- player->p_angle) * (M_PI / 180));
		else if (player->r_angle >= 330)
			(*game)->player->correct_dis *= cos((player->r_angle
						- player->p_angle) * (M_PI / 180));
	}
	else
		(*game)->player->correct_dis *= cos((player->r_angle
					- player->p_angle) * (M_PI / 180));
}

void	cub_draw_column(t_game **game, t_map *map, t_player *pl,
						t_window *win)
{
	(void)map;
	cub_grid_div_verti(game, pl);
	cub_grid_div_hori(game, pl);
	if (pl->verti_dis < pl->horiz_dis)
	{
		(*game)->player->correct_dis = pl->verti_dis;
		//check whether its east or west of block
		(*game)->player->side = EAST;
		if ((*game)->map->segment[(*game)->start]->player_found)
			cub_bressenham(pl->x_m_grid, pl->y_m_grid, pl->verti_i, *game);
	}
	else if (pl->horiz_dis < pl->verti_dis)
	{
		(*game)->player->correct_dis = pl->horiz_dis;
		//check whether its north or south of block
		(*game)->player->side = NORTH;
		if ((*game)->map->segment[(*game)->start]->player_found)
			cub_bressenham(pl->x_m_grid, pl->y_m_grid, pl->horiz_i, *game);
	}
	if (pl->r_angle != pl->p_angle)
		cub_correct_distance(game, pl);
	if (pl->correct_dis)
		cub_prep_column(*game, map, pl, win);
	else
		printf("ERROR OCCURED IN CALCULATING CORRECT DISTANCE\n at r_angle: %f \
		and p_angle: %f", pl->r_angle, pl->p_angle);
}
