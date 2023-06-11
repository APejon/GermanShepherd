/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_inputs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:24:15 by amalbrei          #+#    #+#             */
/*   Updated: 2023/06/11 17:58:22 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	cub_move_player(int key, t_game **game)
{
	if (key == 13)
		(*game)->player->y_m_grid -= 1.0;
	if (key == 1)
		(*game)->player->y_m_grid += 1.0;
	if (key == 0)
		(*game)->player->x_m_grid -= 1.0;
	if (key == 2)
		(*game)->player->x_m_grid += 1.0;
}

void	cub_enlarge_map(int key, t_game **game)
{
	if (key == 46)
	{
		if ((*game)->m_mag == 1)
			(*game)->m_mag = 2;
		else if ((*game)->m_mag == 2)
			(*game)->m_mag = 1;
		cub_prep_image(*game, &((*game)->win), 'n');
		mlx_put_image_to_window((*game)->win->mlx, (*game)->win->window,
			(*game)->win->addr->i_p, 0, 0);
		mlx_destroy_image((*game)->win->mlx, (*game)->win->addr->i_p);
	}
}

void	cub_change_map(int key, t_game **game)
{
	int	i;

	i = 0;
	if (key == 18)
	{
		if ((*game)->start < (*game)->no_of_segments - 1)
			(*game)->start++;
		else
			(*game)->start = 0;
	}
	if (key == 19)
	{
		while (!(*game)->map->segment[i]->player_found)
			i++;
		(*game)->start = i;
	}
	cub_enlarge_map(key, game);
}

void	cub_esc(int key, t_game **game)
{
	if (key == 53)
	{
		mlx_clear_window((*game)->win->mlx, (*game)->win->window);
		cub_free_map(game);
		cub_free_segments(game);
		ft_free(&((*game)->map));
		ft_free(&((*game)->player->verti_i));
		ft_free(&((*game)->player->horiz_i));
		ft_free(&((*game))->player);
		ft_free(&((*game)->win->addr));
		ft_free(&((*game)->win));
		ft_free(&((*game)));
		exit(0);
	}
}

int	cub_inputs(int key, t_game **game)
{
	cub_esc(key, game);
	cub_change_map(key, game);
	cub_move_player(key, game);
	cub_draw(*game);
	return (0);
}
