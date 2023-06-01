/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_draw_ui.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchernys <gchernys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:01:03 by amalbrei          #+#    #+#             */
/*   Updated: 2023/06/01 14:13:30 by gchernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	cub_draw_outline(t_game *game, t_bress bress)
{
	bress.x -= 1;
	my_mlx_pixel_put(game, bress.x, bress.y);
	bress.y -= 1;
	my_mlx_pixel_put(game, bress.x, bress.y);
	bress.x += 1;
	my_mlx_pixel_put(game, bress.x, bress.y);
	bress.x += 1;
	my_mlx_pixel_put(game, bress.x, bress.y);
	bress.y += 1;
	my_mlx_pixel_put(game, bress.x, bress.y);
	bress.y += 1;
	my_mlx_pixel_put(game, bress.x, bress.y);
	bress.x -= 1;
	my_mlx_pixel_put(game, bress.x, bress.y);
	bress.x -= 1;
	my_mlx_pixel_put(game, bress.x, bress.y);
}

void	cub_draw_cursor(t_game *game, t_player *player)
{
	int		i;
	t_bress	bress;

	i = 0;
	if (game->map->segment[game->start]->player_found)
	{
		game->color = 0x00FF0000;
		bress.x = player->x_m_grid * game->m_mag;
		bress.y = player->y_m_grid * game->m_mag;
		my_mlx_pixel_put(game, bress.x, bress.y);
		cub_draw_outline(game, bress);
	}
}

void	cub_turn_transparent(t_game *game, char flag)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (flag == 'T')
		game->color = 0xFF000000;
	else if (flag == 'B')
		game->color = 0x00000000;
	while (y <= game->m_height)
	{
		x = 0;
		while (x <= game->m_width)
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
	cub_prep_image(&(game->win));
	cub_draw_floor_and_ceiling(game);
	cub_turn_transparent(game, 'T');
	cub_draw_grid(game, game->map->segment[game->start]->grid);
	cub_print_m_info(game);
	cub_draw_cursor(game, game->player);
}
