/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_bressenham.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:46:13 by amalbrei          #+#    #+#             */
/*   Updated: 2023/06/22 15:46:14 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	cub_bressenham_decision(t_game *game, t_bress *bress, int i)
{
	game->color = 0xbf8b0000;
	while (i < bress->x_step)
	{
		if (bress->x < game->m_width - 20 && bress->y < game->m_height - 30)
			my_mlx_pixel_put(game, bress->x, bress->y);
		if (bress->p > 0)
		{
			bress->p = bress->p + (2 * (bress->y_step - bress->x_step));
			if (bress->swap)
				bress->x += bress->signx;
			else
				bress->y += bress->signy;
		}
		else
			bress->p = bress->p + 2 * bress->y_step;
		if (bress->swap)
			bress->y += bress->signy;
		else
			bress->x += bress->signx;
		if ((game->player->r_angle >= 269.9 && game->player->r_angle <= 270.0)
			|| (game->player->r_angle >= 89.9 && game->player->r_angle <= 90.0))
			bress->x = bress->deltax[0];
		i++;
	}
}

void	cub_bressenham_frag(t_game *game, t_bress *bress)
{
	int	i;

	bress->x_step = (int)fabs(bress->deltax[1] - bress->deltax[0]);
	bress->y_step = (int)fabs(bress->deltay[1] - bress->deltay[0]);
	bress->swap = 0;
	bress->x = (int)bress->deltax[0];
	bress->y = (int)bress->deltay[0];
	bress->p = (2 * bress->y_step) - bress->x_step;
	i = 0;
	if (bress->y_step >= bress->x_step)
	{
		bress->temp = bress->x_step;
		bress->x_step = bress->y_step;
		bress->y_step = bress->temp;
		bress->swap = 1;
	}
	cub_bressenham_decision(game, bress, i);
	ft_free(&bress);
}

void	cub_realign(t_bress *bress, t_game *game)
{
	while (bress->x_check < (game->player->x_pos / (double)game->grid_size))
	{
		bress->x_check += 34;
		bress->x_shift++;
	}
	while (bress->x_shift-- > 0)
		bress->deltax[1] -= 544;
	while (bress->y_check < (game->player->y_pos / (double)game->grid_size))
	{
		bress->y_check += 14;
		bress->y_shift++;
	}
	while (bress->y_shift-- > 0)
		bress->deltay[1] -= 224;
}

void	cub_bressenham(double x, double y, double *delta, t_game *game)
{
	t_bress	*bress;

	bress = calloc(1, sizeof(t_bress));
	bress->x_shift = 0.0;
	bress->y_shift = 0.0;
	bress->x_check = 34.0;
	bress->y_check = 14.0;
	bress->deltax[0] = x * (game->m_mag);
	bress->deltay[0] = y * (game->m_mag);
	bress->deltax[1] = (delta[0] + (double)game->m_xset)
		* ((double)game->m_zoom);
	bress->deltay[1] = (delta[1] + (double)game->m_yset)
		* ((double)game->m_zoom);
	cub_realign(bress, game);
	bress->signx = 1;
	bress->signy = 1;
	if (bress->deltax[1] - bress->deltax[0] < 0)
		bress->signx = -1;
	if (bress->deltay[1] - bress->deltay[0] < 0)
		bress->signy = -1;
	cub_bressenham_frag(game, bress);
}
