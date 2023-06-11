/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 18:05:07 by amalbrei          #+#    #+#             */
/*   Updated: 2023/06/11 17:59:45 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	cub_draw(t_game *game)
{
	game->m_zoom = (game->grid_size / 4) * game->m_mag;
	game->win_x = 0;
	game->player->hit = 0;
	game->player->side = 0;
	game->player->verti_dis = INT_MAX;
	game->player->horiz_dis = INT_MAX;
	game->player->correct_dis = 0;
	game->player->r_angle = game->player->p_angle + (game->player->fov / 2);
	cub_draw_ui(game);
	cub_calc_player(&(game), game->player, game->win);
}

void	cub_window_init(t_window **win)
{
	(*win)->addr = malloc(sizeof(t_addr));
	if (!(*win)->addr)
		exit (MALLOC_ERR);
	(*win)->mlx = mlx_init();
	(*win)->window_w = 1280;
	(*win)->window_h = 1280;
	(*win)->window = mlx_new_window((*win)->mlx, (*win)->window_w,
			(*win)->window_h, "Cub3D Clear To Fly");
}

void	cub_player_init(t_game **game)
{
	cub_find_player(game, (*game)->map);
	(*game)->player->fov = 60;
	(*game)->player->height = 32;
	if ((*game)->player->dir == 'N')
		(*game)->player->p_angle = 90.0;
	if ((*game)->player->dir == 'W')
		(*game)->player->p_angle = 180.0;
	if ((*game)->player->dir == 'S')
		(*game)->player->p_angle = 270.0;
	if ((*game)->player->dir == 'E')
		(*game)->player->p_angle = 0.0;
	(*game)->player->r_angle = (*game)->player->p_angle
		+ ((*game)->player->fov / 2);
	(*game)->player->x_pos = ((*game)->player->x * (*game)->grid_size)
		+ ((*game)->grid_size / 2);
	(*game)->player->y_pos = ((*game)->player->y * (*game)->grid_size)
		+ ((*game)->grid_size / 2);
	(*game)->player->project_dis = ((*game)->win->window_w / 2)
		/ tan(((*game)->player->fov / 2) * (M_PI / 180));
}

void	cub_init(t_game *game)
{
	cub_window_init(&(game->win));
	cub_player_init(&(game));
	cub_draw(game);
}
