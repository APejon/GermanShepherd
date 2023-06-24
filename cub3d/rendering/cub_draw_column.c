/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_draw_column.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchernys <gchernys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 14:00:33 by amalbrei          #+#    #+#             */
/*   Updated: 2023/06/24 23:09:41 by gchernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	cub_put_column(t_game *game, t_map *map, int draw_start, int draw_end, int wall_height)
{
	int	y;
	int size;
	void *img_ptr;
	int noneed;
	
	(void)map;
	y = 0;
	(void)size;
	if (game->win_x <= game->m_width)
	{
		while (y <= game->m_height)
			y++;
	}
	while (y < draw_start)
		y = draw_start;
	double step = 64.0 / wall_height;
	int texX;
	if (game->player->horiz_dis < game->player->verti_dis)
		texX = floor(game->player->horiz_i[0] * 64.0);
	else
		texX = floor(game->player->verti_i[1] * 64.0);
	// printf("%d\n", texX);
	double texPos = (draw_start - game->win->window_h / 2 + wall_height / 2) * step;
	// printf("%f\n", texPos);
	while (y < draw_end)
	{
		int texY = (int)texPos & (64);
		texPos += step;
		if (game->player->side == NORTH)
			game->color = game->tex_north[64 * texY + texX];
		else if (game->player->side == SOUTH)
			game->color = game->tex_south[64 * texY + texX];
		else if (game->player->side == EAST)
			game->color = game->tex_east[64 * texY + texX];
		else if (game->player->side == WEST)
			game->color = game->tex_west[64 * texY + texX];
		// game->color = (game->color >> 1) & 8355711;
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
	cub_put_column(game, map, draw_start, draw_end, wall_height);
}

void	cub_correct_distance(t_game **game, t_player *player)
{
	if (player->r_angle == player->p_angle - 30)
		player->fl_coll = (*game)->player->correct_dis;
	if (player->r_angle == player->p_angle + 30)
		player->fr_coll = (*game)->player->correct_dis;
	player->bl_coll = cub_back_collisions(game, player, player->p_angle + 150);
	player->br_coll = cub_back_collisions(game, player, player->p_angle - 150);
	player->l_coll = cub_back_collisions(game, player, player->p_angle + 90);
	player->r_coll = cub_back_collisions(game, player, player->p_angle - 90);
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
