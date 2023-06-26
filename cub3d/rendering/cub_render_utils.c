/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_render_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 14:23:19 by amalbrei          #+#    #+#             */
/*   Updated: 2023/06/26 20:04:39 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	cub_reset_scaling(t_game *game, int i)
{
	game->tex[i]->repeat = 0;
	game->tex[i]->skip = 0;
}

void	cub_check_scaling(t_texture **tex, int i, int y)
{
	tex[i]->tex_i = 1.0 * abs(y - tex[i]->draw_start)
		/ abs(tex[i]->draw_end - tex[i]->draw_start) * tex[i]->t_height;
}

int	cub_check_side(int side)
{
	int	i;

	if (side == NORTH)
		i = 0;
	else if (side == SOUTH)
		i = 1;
	else if (side == EAST)
		i = 2;
	else
		i = 3;
	return (i);
}
