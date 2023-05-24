/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_draw_ui.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:01:03 by amalbrei          #+#    #+#             */
/*   Updated: 2023/05/23 17:44:09 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	cub_turn_transparent(t_game *game, t_window *win)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	game->color = 0xFF000000;
	while (y <= win->window_h)
	{
		x = 0;
		while (x <= win->window_w)
		{
			my_mlx_pixel_put(game, x, y);
			x++;
		}
		y++;
	}
}

void	cub_draw_ui(t_game *game)
{
	cub_draw_m_background(game, game->win);
	mlx_put_image_to_window(game->win->mlx, game->win->window,
		game->win->addr->i_p, 0, 0);
	mlx_destroy_image(game->win->mlx, game->win->addr->i_p);
	cub_prep_image(&(game->win));
	cub_turn_transparent(game, game->win);
	cub_draw_grid(game, game->map->segment[game->start]->grid);
	// cub_draw_cursor(game, game->map);
	mlx_put_image_to_window(game->win->mlx, game->win->window,
		game->win->addr->i_p, 0, 0);
	mlx_destroy_image(game->win->mlx, game->win->addr->i_p);
}
