/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 18:05:07 by amalbrei          #+#    #+#             */
/*   Updated: 2023/06/06 18:06:16 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	cub_place_image(t_window **win)
{
	mlx_put_image_to_window((*win)->mlx, (*win)->window,
		(*win)->addr->i_p, 0, 0);
	mlx_destroy_image((*win)->mlx, (*win)->addr->i_p);
}

void	cub_prep_image(t_window **win)
{
	(*win)->addr->i_p = mlx_new_image((*win)->mlx, (*win)->window_w,
			(*win)->window_h);
	(*win)->addr->ad = mlx_get_data_addr((*win)->addr->i_p,
			&((*win)->addr->pix_bi), &((*win)->addr->line_by),
			&((*win)->addr->endian));
}

void	cub_draw(t_game *game)
{
	game->m_zoom = (game->grid_size / 4) * game->m_mag;
	game->player->verti_dis = INT_MAX;
	game->player->horiz_dis = INT_MAX;
	cub_calc_player(&(game));
	cub_draw_ui(game);
}

void	cub_window_init(t_window **win)
{
	(*win)->addr = malloc(sizeof(t_addr));
	if (!(*win)->addr)
		exit (MALLOC_ERR);
	(*win)->mlx = mlx_init();
	(*win)->window_w = 1280;
	(*win)->window_h = 1024;
	(*win)->window = mlx_new_window((*win)->mlx, (*win)->window_w,
			(*win)->window_h, "Cub3D Clear To Fly");
}

void	cub_init(t_game *game)
{
	cub_player_init(&(game));
	cub_window_init(&(game->win));
	cub_draw(game);
}
