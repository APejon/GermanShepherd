/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_bressenham.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:17:57 by amalbrei          #+#    #+#             */
/*   Updated: 2023/05/19 18:58:01 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	my_mlx_pixel_put(t_game *game, int x, int y)
{
	char	*dst;

	if ((x >= 0 && y >= 0) && (x < game->win->window_w
			&& y < game->win->window_h))
	{
		dst = game->win->addr->ad + (y * game->win->addr->line_by + x
				* (game->win->addr->pix_bi / 8));
		*(unsigned int *)dst = game->color;
	}
}

void	cub_bressenham_decision(t_game *game, t_bress *bress, int i)
{
	while (i < bress->x_step)
	{
		my_mlx_pixel_put(game, bress->x, bress->y);
		if (bress->p > 0)
		{
			bress->p = bress->p + (2 * (bress->y_step - bress->x_step));
			if (bress->swap)
				bress->x += bress->sign1;
			else
				bress->y += bress->sign2;
		}
		else
			bress->p = bress->p + 2 * bress->y_step;
		if (bress->swap)
			bress->y += bress->sign2;
		else
			bress->x += bress->sign1;
		i++;
	}
}

void	cub_bressenham_frag(t_game *game, t_bress *bress)
{
	int	i;

	bress->x_step = abs(bress->deltax[1] - bress->deltax[0]);
	bress->y_step = abs(bress->deltay[1] - bress->deltay[0]);
	bress->swap = 0;
	if (bress->y_step >= bress->x_step)
	{
		bress->temp = bress->x_step;
		bress->x_step = bress->y_step;
		bress->y_step = bress->temp;
		bress->swap = 1;
	}
	bress->x = bress->deltax[0];
	bress->y = bress->deltay[0];
	bress->p = (2 * bress->y_step) - bress->x_step;
	i = 0;
	cub_bressenham_decision(game, bress, i);
	ft_free(&bress);
}

void	cub_bressenham(int x, int y, t_game *game, char flag)
{
	t_bress	*bress;

	bress = calloc(1, sizeof(t_bress));
	if (flag == 'x')
	{
		bress->deltax[0] = x * (game->m_zoom);
		bress->deltay[0] = y * (game->m_zoom);
		bress->deltax[1] = (x + 1) * (game->m_zoom);
		bress->deltay[1] = y * (game->m_zoom);
	}
	if (flag == 'y')
	{
		bress->deltax[0] = x * (game->m_zoom);
		bress->deltay[0] = y * (game->m_zoom);
		bress->deltax[1] = x * (game->m_zoom);
		bress->deltay[1] = (y + 1) * (game->m_zoom);
	}
	bress->sign1 = 1;
	bress->sign2 = 1;
	if (bress->deltax[1] - bress->deltax[0] < 0)
		bress->sign1 = -1;
	if (bress->deltay[1] - bress->deltay[0] < 0)
		bress->sign2 = -1;
	cub_bressenham_frag(game, bress);
}
