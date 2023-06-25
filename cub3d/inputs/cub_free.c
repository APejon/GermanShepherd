/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:53:43 by amalbrei          #+#    #+#             */
/*   Updated: 2023/06/25 12:52:11 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	cub_free_textures(t_game *game)
{
	int	i;

	i = 0;
	while (++i < 4)
	{
		mlx_destroy_image(game->win->mlx, game->tex[i]->i_p);
		ft_free(&game->tex[i]);
	}
	ft_free(&game->tex);
}

void	cub_free_segments(t_game **game)
{
	int	i;
	int	j;

	i = -1;
	while ((*game)->map->segment[++i])
	{
		j = -1;
		while ((*game)->map->segment[i]->grid[++j])
			ft_free(&(*game)->map->segment[i]->grid[j]);
		ft_free(&(*game)->map->segment[i]->grid);
		ft_free(&(*game)->map->segment[i]);
	}
	ft_free(&(*game)->map->segment);
}

void	cub_free_map(t_game **game)
{
	int	i;

	i = -1;
	while (++i < (*game)->map->high)
	{
		ft_free(&(*game)->map->map[i]);
		if (i < (*game)->map->high - 6)
			ft_free(&(*game)->map->full_grid[i]);
	}
	ft_free(&((*game)->map->map));
	ft_free(&(*game)->map->full_grid);
}
