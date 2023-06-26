/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_render_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 14:23:19 by amalbrei          #+#    #+#             */
/*   Updated: 2023/06/26 14:54:17 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	cub_reset_scaling(t_game *game, int i)
{
	game->tex[i]->repeat = 0;
	game->tex[i]->skip = 0;
}

void	cub_check_scaling(t_texture **tex, int i)
{
	if (tex[i]->scale > 1)
	{
		tex[i]->repeat++;
		if (tex[i]->repeat >= tex[i]->scale)
		{
			tex[i]->repeat -= tex[i]->scale;
			tex[i]->tex_i++;
		}
	}
	else if (tex[i]->scale < 1)
	{
		tex[i]->skip = tex[i]->scale;
		tex[i]->tex_i += ceil(tex[i]->skip);
	}
	else
		tex[i]->tex_i++;
}

void	cub_start_index(t_texture **tex, int i, int draw_start)
{
	tex[i]->scale = (double)(tex[i]->draw_end - tex[i]->draw_start)
		/ (double)tex[i]->t_height;
	tex[i]->tex_i = 0;
	while (tex[i]->draw_start != draw_start)
	{
		cub_check_scaling(tex, i);
		tex[i]->draw_start++;
	}
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
