/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_inputs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchernys <gchernys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:24:15 by amalbrei          #+#    #+#             */
/*   Updated: 2023/06/21 15:10:26 by gchernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	cub_change_speed(t_game **game)
{
	if ((*game)->keys->shift == true)
		(*game)->player->speed = 6;
	else if ((*game)->keys->shift == false)
		(*game)->player->speed = 4;
}

void	cub_turn_player(t_game **game)
{
	if ((*game)->keys->l_arrow == true)
		(*game)->player->p_angle += (*game)->player->speed;
	if ((*game)->keys->r_arrow == true)
		(*game)->player->p_angle -= (*game)->player->speed;
	if ((*game)->player->p_angle > 359.0)
		(*game)->player->p_angle = (*game)->player->p_angle - 360;
	if ((*game)->player->p_angle < 0.0)
		(*game)->player->p_angle = (*game)->player->p_angle + 360;
}

void	cub_strafe_player(t_game **game, t_player *player)
{
	if ((*game)->keys->a == true)
	{
		(*game)->player->y_pos -= sin((player->p_angle + 90) * (M_PI / 180))
			* player->speed;
		(*game)->player->x_pos += cos((player->p_angle + 90) * (M_PI / 180))
			* player->speed;
		(*game)->player->y_m_grid -= sin((player->p_angle + 90) * (M_PI / 180))
			* player->speed / 4.0;
		(*game)->player->x_m_grid += cos((player->p_angle + 90) * (M_PI / 180))
			* player->speed / 4.0;
	}
	if ((*game)->keys->d == true)
	{
		(*game)->player->y_pos -= sin((player->p_angle - 90) * (M_PI / 180))
			* (*game)->player->speed;
		(*game)->player->x_pos += cos((player->p_angle - 90) * (M_PI / 180))
			* (*game)->player->speed;
		(*game)->player->y_m_grid -= sin((player->p_angle - 90) * (M_PI / 180))
			* player->speed / 4.0;
		(*game)->player->x_m_grid += cos((player->p_angle - 90) * (M_PI / 180))
			* player->speed / 4.0;
	}
}

void	cub_move_player(t_game **game, t_player *player)
{
	if ((*game)->keys->w == true)
	{
		(*game)->player->y_pos -= sin(player->p_angle * (M_PI / 180))
			* player->speed;
		(*game)->player->x_pos += cos(player->p_angle * (M_PI / 180))
			* player->speed;
		(*game)->player->y_m_grid -= sin(player->p_angle * (M_PI / 180))
			* player->speed / 4.0;
		(*game)->player->x_m_grid += cos(player->p_angle * (M_PI / 180))
			* player->speed / 4.0;
	}
	if ((*game)->keys->s == true)
	{
		(*game)->player->y_pos += sin(player->p_angle * (M_PI / 180))
			* (*game)->player->speed;
		(*game)->player->x_pos -= cos(player->p_angle * (M_PI / 180))
			* (*game)->player->speed;
		(*game)->player->y_m_grid += sin(player->p_angle * (M_PI / 180))
			* player->speed / 4.0;
		(*game)->player->x_m_grid -= cos(player->p_angle * (M_PI / 180))
			* player->speed / 4.0;
	}
}

int	cub_inputs(t_game **game)
{
	cub_move_player(game, (*game)->player);
	cub_strafe_player(game, (*game)->player);
	cub_undo(game, (*game)->map, (*game)->player);
	cub_turn_player(game);
	cub_change_speed(game);
	cub_map_bound(game, (*game)->player,
		(*game)->map->segment[(*game)->start]);
	cub_draw(*game);
	return (0);
}
