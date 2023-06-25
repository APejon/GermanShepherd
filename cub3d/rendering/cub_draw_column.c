/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_draw_column.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 14:00:33 by amalbrei          #+#    #+#             */
/*   Updated: 2023/06/25 17:31:59 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	cub_get_tex_colour(t_game *game, t_texture **tex, int i)
{
	int	colour;

	if (i == 2 || i == 3)
		tex[i]->tex_pointer = floor((int)game->player->verti_i[1]
				% game->grid_size);
	else if (i == 0 || i == 1)
		tex[i]->tex_pointer = floor((int)game->player->horiz_i[0]
				% game->grid_size);
	tex[i]->tex_pointer += (tex[i]->t_width * tex[i]->tex_i);
	colour = tex[i]->ad[tex[i]->tex_pointer];
	return (colour);
}

void	cub_put_column(t_game *game, t_texture **tex, int draw_st, int draw_end)
{
	int	y;
	int	i;

	y = 0;
	i = cub_check_side(game, game->player->side, draw_end - draw_st);
	tex[i]->tex_i = 0;
	while (y < draw_st)
		y++;
	while (y >= draw_st && y <= draw_end && y <= game->win->window_h)
	{
		cub_check_scaling(game, game->tex, i);
		if (game->win_x <= game->m_width)
		{
			if (y <= game->m_height)
			{
				y++;
				continue ;
			}
		}
		game->color = cub_get_tex_colour(game, tex, i);
		my_mlx_pixel_put(game, game->win_x, y);
		y++;
	}
	cub_reset_scaling(game, i);
	game->win_x++;
}

void	cub_prep_column(t_game *game, t_player *player, t_window *win)
{
	int	wall_height;
	int	draw_start;
	int	draw_end;

	wall_height = (int)ceil(game->grid_size / player->correct_dis
			* player->project_dis);
	draw_start = (win->window_h / 2) - (wall_height / 2);
	if (draw_start < 0)
		draw_start = 0;
	draw_end = (win->window_h / 2) + (wall_height / 2);
	if (draw_end > win->window_h)
		draw_end = win->window_h;
	cub_put_column(game, game->tex, draw_start, draw_end);
}

void	cub_correct_distance(t_game **game, t_player *player)
{
	if (player->r_angle == player->p_angle - 30)
		player->fl_coll = (*game)->player->correct_dis;
	if (player->r_angle == player->p_angle + 30)
		player->fr_coll = (*game)->player->correct_dis;
	player->fl2_coll = cub_back_collisions(game, player, player->p_angle - 60);
	player->fr2_coll = cub_back_collisions(game, player, player->p_angle + 60);
	player->l_coll = cub_back_collisions(game, player, player->p_angle - 90);
	player->r_coll = cub_back_collisions(game, player, player->p_angle + 90);
	player->bl2_coll = cub_back_collisions(game, player, player->p_angle - 120);
	player->br2_coll = cub_back_collisions(game, player, player->p_angle + 120);
	player->bl_coll = cub_back_collisions(game, player, player->p_angle - 150);
	player->br_coll = cub_back_collisions(game, player, player->p_angle + 150);
	(*game)->player->correct_dis *= cos((player->r_angle
				- player->p_angle) * (M_PI / 180));
}

void	cub_draw_column(t_game **game, t_player *pl, t_window *win)
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
		cub_prep_column(*game, pl, win);
}
