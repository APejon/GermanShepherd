/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_inputs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:24:15 by amalbrei          #+#    #+#             */
/*   Updated: 2023/05/22 14:15:55 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	cub_esc(int key, t_game **game)
{
	int	i;

	i = -1;
	if (key == 53)
	{
		mlx_clear_window((*game)->win->mlx, (*game)->win->window);
		while (++i < (*game)->map->high)
			ft_free(&(*game)->map->map[i]);
		ft_free(&((*game)->map->map));
		// i = -1;
		// while (++i < (*game)->map->high - 6)
		// 	ft_free(&(*game)->map->grid[i]);
		// ft_free(&((*game)->map->grid));
		i = -1;
		while ((*game)->map->segment[++i])
			ft_free(&(*game)->map->segment[i]);
		ft_free(&(*game)->map->segment);
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
	// cub_draw(*game);
	return (0);
}
