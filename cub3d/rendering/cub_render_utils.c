/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_render_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 14:23:19 by amalbrei          #+#    #+#             */
/*   Updated: 2023/06/25 17:18:23 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	cub_reset_scaling(t_game *game, int i)
{
	game->tex[i]->repeat = 0;
	game->tex[i]->skip = 0;
}

void	cub_check_scaling(t_game *game, t_texture **tex, int i)
{
	if (tex[i]->scale > 1)
	{
		game->tex[i]->repeat++;
		if (tex[i]->repeat >= tex[i]->scale)
		{
			game->tex[i]->repeat = 0;
			tex[i]->tex_i++;
		}
	}
	else if (tex[i]->scale < 1)
	{
		game->tex[i]->skip = tex[i]->scale * 0.5;
		tex[i]->tex_i += game->tex[i]->skip;
	}
	else
		return ;
}

int	cub_check_side(t_game *game, int side, int wall_height)
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
	game->tex[i]->scale = (double)wall_height / (double)game->tex[i]->t_height;
	return (i);
}
