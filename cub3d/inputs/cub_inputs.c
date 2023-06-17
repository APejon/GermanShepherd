/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_inputs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:24:15 by amalbrei          #+#    #+#             */
/*   Updated: 2023/06/17 15:14:38 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	cub_move_player(t_game **game)
{
	if ((*game)->keys->w == true)
		(*game)->player->y_m_grid -= 1.0;
	if ((*game)->keys->s == true)
		(*game)->player->y_m_grid += 1.0;
	if ((*game)->keys->a == true)
		(*game)->player->x_m_grid -= 1.0;
	if ((*game)->keys->d == true)
		(*game)->player->x_m_grid += 1.0;
	if ((*game)->keys->l_arrow == true)
		(*game)->player->p_angle += 2.0;
	if ((*game)->keys->r_arrow == true)
		(*game)->player->p_angle -= 2.0;
	if ((*game)->player->p_angle > 359.0)
		(*game)->player->p_angle = (*game)->player->p_angle - 360;
	if ((*game)->player->p_angle < 0.0)
		(*game)->player->p_angle = (*game)->player->p_angle + 360;
}

void	cub_enlarge_map(t_game **game)
{
	if ((*game)->m_mag == 1)
		(*game)->m_mag = 2;
	else if ((*game)->m_mag == 2)
		(*game)->m_mag = 1;
}

void	cub_change_map(t_game **game)
{
	int	i;

	i = 0;
	if ((*game)->keys->m_switch)
	{
		if ((*game)->start < (*game)->no_of_segments - 1)
				(*game)->start++;
		else
				(*game)->start = 0;
	}
	if ((*game)->keys->m_player)
	{
		while (!(*game)->map->segment[i]->player_found)
			i++;
		(*game)->start = i;
	}
}

void	cub_esc(t_game **game)
{
	mlx_clear_window((*game)->win->mlx, (*game)->win->window);
	cub_free_map(game);
	cub_free_segments(game);
	ft_free(&((*game)->keys));
	ft_free(&((*game)->win->addr));
	ft_free(&((*game)->win));
	ft_free(&((*game)->player->verti_i));
	ft_free(&((*game)->player->horiz_i));
	ft_free(&((*game))->player);
	ft_free(&((*game)->map));
	ft_free(&((*game)));
	exit(0);
}

int	cub_inputs(t_game **game)
{
	cub_move_player(game);
	cub_draw(*game);
	return (0);
}
