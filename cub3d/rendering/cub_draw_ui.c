/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_draw_ui.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchernys <gchernys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:01:03 by amalbrei          #+#    #+#             */
/*   Updated: 2023/06/21 14:13:37 by gchernys         ###   ########.fr       */
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
	t_bress	bress;

	if (game->map->segment[game->start]->player_found)
	{
		game->color = 0x00FF0000;
		bress.x = player->x_m_grid * game->m_mag;
		bress.y = player->y_m_grid * game->m_mag;
		my_mlx_pixel_put(game, bress.x, bress.y);
		cub_draw_outline(game, bress);
	}
}

<<<<<<< HEAD
void	cub_turn_transparent(t_game *game, char flag)
=======
void	cub_turn_transparent(t_game *game, int width, int height, int *start)
>>>>>>> 4dd4a52c31382f8dc38907827f398d1fcfe8d3f0
{
	int	x;
	int	y;

	x = 0;
	y = 0;
<<<<<<< HEAD
	if (flag == 'T')
		game->color = 0xFF000000;
	else if (flag == 'B')
		game->color = 0x00000000;
	while (y <= game->m_height)
	{
		x = 0;
		while (x <= game->m_width)
=======
	game->color = 0xFF000000;
	while (y <= height)
	{
		x = -1;
		if (y < start[1])
>>>>>>> 4dd4a52c31382f8dc38907827f398d1fcfe8d3f0
		{
			while (++x <= start[0])
				my_mlx_pixel_put(game, x, y);
			if (y == start[1] - 1)
				break ;
		}
		else
		{
			while (++x <= width)
				my_mlx_pixel_put(game, x, y);
		}
		y++;
	}
}

void	cub_draw_ui(t_game *game)
{
<<<<<<< HEAD
	cub_draw_m_background(game, game->win);
	cub_prep_image(&(game->win));
	cub_draw_floor_and_ceiling(game);
	cub_turn_transparent(game, 'T');
=======
	cub_prep_image(game, &(game->win), 'm');
>>>>>>> 4dd4a52c31382f8dc38907827f398d1fcfe8d3f0
	cub_draw_grid(game, game->map->segment[game->start]->grid);
	cub_print_m_info(game);
	cub_draw_cursor(game, game->player);
	cub_place_image(&(game->win));
}
