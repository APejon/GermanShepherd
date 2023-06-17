/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 13:19:50 by amalbrei          #+#    #+#             */
/*   Updated: 2023/06/17 15:11:46 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	cub_movement(int key, t_game **game)
{
	if (key == 13)
		(*game)->keys->w = true;
	if (key == 1)
		(*game)->keys->s = true;
	if (key == 0)
		(*game)->keys->a = true;
	if (key == 2)
		(*game)->keys->d = true;
	if (key == 123)
		(*game)->keys->l_arrow = true;
	if (key == 124)
		(*game)->keys->r_arrow = true;
}

int	cub_key_press(int key, t_game **game)
{
	cub_movement(key, game);
	if (key == 46)
		cub_enlarge_map(game);
	if (key == 18 || key == 19)
	{
		if (key == 18)
			(*game)->keys->m_switch = true;
		if (key == 19)
			(*game)->keys->m_player = true;
		cub_change_map(game);
	}
	if (key == 53)
		cub_esc(game);
	return (0);
}

int	cub_key_release(int key, t_game **game)
{
	if (key == 13)
		(*game)->keys->w = false;
	if (key == 1)
		(*game)->keys->s = false;
	if (key == 0)
		(*game)->keys->a = false;
	if (key == 2)
		(*game)->keys->d = false;
	if (key == 123)
		(*game)->keys->l_arrow = false;
	if (key == 124)
		(*game)->keys->r_arrow = false;
	if (key == 18)
		(*game)->keys->m_switch = false;
	if (key == 19)
		(*game)->keys->m_player = false;
	return (0);
}
