/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_inputs_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 19:09:50 by amalbrei          #+#    #+#             */
/*   Updated: 2023/06/19 19:26:53 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	cub_undo_cont2(t_game **game, t_player *player)
{
	if ((*game)->keys->a == true)
	{
		(*game)->player->y_pos += sin((player->p_angle + 90) * (M_PI / 180))
			* player->speed;
		(*game)->player->x_pos -= cos((player->p_angle + 90) * (M_PI / 180))
			* player->speed;
		(*game)->player->y_m_grid += sin((player->p_angle + 90) * (M_PI / 180))
			* player->speed / 4.0;
		(*game)->player->x_m_grid -= cos((player->p_angle + 90) *(M_PI / 180))
			* player->speed / 4.0;
	}
	else if ((*game)->keys->d == true)
	{
		(*game)->player->y_pos += sin((player->p_angle - 90) * (M_PI / 180))
			* (*game)->player->speed;
		(*game)->player->x_pos -= cos((player->p_angle - 90) * (M_PI / 180))
			* (*game)->player->speed;
		(*game)->player->y_m_grid += sin((player->p_angle - 90) * (M_PI / 180))
			* player->speed / 4.0;
		(*game)->player->x_m_grid -= cos((player->p_angle - 90) * (M_PI / 180))
			* player->speed / 4.0;
	}
}

void	cub_undo_cont(t_game **game, t_player *player)
{
	if ((*game)->keys->s == true)
	{
		(*game)->player->y_pos -= sin(player->p_angle * (M_PI / 180))
			* (*game)->player->speed;
		(*game)->player->x_pos += cos(player->p_angle * (M_PI / 180))
			* (*game)->player->speed;
		(*game)->player->y_m_grid -= sin(player->p_angle * (M_PI / 180))
			* player->speed / 4.0;
		(*game)->player->x_m_grid += cos(player->p_angle * (M_PI / 180))
			* player->speed / 4.0;
	}
}

void	cub_undo(t_game **game, t_map *map, t_player *player)
{
	if (map->full_grid[(int)player->y_pos / 64][(int)player->x_pos / 64] == '1')
	{
		if ((*game)->keys->w == true)
		{
			(*game)->player->y_pos += sin(player->p_angle * (M_PI / 180))
				* player->speed;
			(*game)->player->x_pos -= cos(player->p_angle * (M_PI / 180))
				* player->speed;
			(*game)->player->y_m_grid += sin(player->p_angle * (M_PI / 180))
				* player->speed / 4.0;
			(*game)->player->x_m_grid -= cos(player->p_angle * (M_PI / 180))
				* player->speed / 4.0;
		}
		cub_undo_cont(game, player);
		cub_undo_cont2(game, player);
	}
}
