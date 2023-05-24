/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_inputs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:24:15 by amalbrei          #+#    #+#             */
/*   Updated: 2023/05/23 18:10:19 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
}

void	cub_esc(int key, t_game **game)
{
	if (key == 53)
	{
		mlx_clear_window((*game)->win->mlx, (*game)->win->window);
		cub_free_map(game);
		cub_free_segments(game);
		ft_free(&(*game)->map->player);
		ft_free(&((*game)->map));
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
	cub_draw(*game);
	return (0);
}
