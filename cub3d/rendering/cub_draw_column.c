/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_draw_column.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 14:00:33 by amalbrei          #+#    #+#             */
/*   Updated: 2023/06/20 17:26:32 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	cub_put_column(t_game *game, t_map *map, int draw_start, int draw_end)
{
	int	y;

	(void)map;
	y = 0;
	if (game->player->side == NORTH)
		game->color = 0x56accbb;
	else if (game->player->side == EAST)
		game->color = 0x194523;
	else if (game->player->side == SOUTH)
		game->color = 0xbba24c;
	else if (game->player->side == WEST)
		game->color = 0x42adef;
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
	draw_start = (win->window_h / 2) - (wall_height / 2) + player->up;
	if (draw_start < 0)
		draw_start = 0;
	draw_end = (win->window_h / 2) + (wall_height / 2) + player->up;
	if (draw_end > win->window_h)
		draw_end = win->window_h;
	cub_put_column(game, map, draw_start, draw_end);
}

void	cub_correct_distance(t_game **game, t_player *player)
{
		(*game)->player->correct_dis *= cos((player->r_angle
				- player->p_angle) * (M_PI / 180));
}

void	cub_draw_column(t_game **game, t_map *map, t_player *pl,
						t_window *win)
{
	if (pl->verti_dis < pl->horiz_dis)
	{
		(*game)->player->correct_dis = pl->verti_dis;
		if (pl->r_angle > 90 && pl->r_angle < 270)
			(*game)->player->side = EAST;
		if (pl->r_angle > 270 || pl->r_angle < 90)
			(*game)->player->side = WEST;
		if ((*game)->map->segment[(*game)->start]->player_found)
			cub_bressenham(pl->x_m_grid, pl->y_m_grid, pl->verti_i, *game);
	}
	else if (pl->horiz_dis <= pl->verti_dis)
	{
		(*game)->player->correct_dis = pl->horiz_dis;
		if (pl->r_angle > 0 && pl->r_angle < 180)
			(*game)->player->side = SOUTH;
		if (pl->r_angle > 180 && pl->r_angle < 360)
			(*game)->player->side = NORTH;
		if ((*game)->map->segment[(*game)->start]->player_found)
			cub_bressenham(pl->x_m_grid, pl->y_m_grid, pl->horiz_i, *game);
	}
	if (pl->r_angle != pl->p_angle)
		cub_correct_distance(game, pl);
	if (pl->correct_dis)
		cub_prep_column(*game, map, pl, win);
}
