/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   segmentation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 14:19:41 by amalbrei          #+#    #+#             */
/*   Updated: 2023/06/01 17:54:12 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	load_full_grid(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 6;
	game->map->full_grid = ft_calloc((game->map->high - 6 + 1), sizeof(char *));
	while (game->map->map[j])
	{
		game->map->full_grid[i] = ft_strdup(game->map->map[j]);
		i++;
		j++;
	}
}

int	count_segments(t_game **game, char **full_grid)
{
	int	total;

	(*game)->m_horizontal = ft_strlen(full_grid[0]);
	(*game)->m_horizontal = ((*game)->m_horizontal / 35) + 1;
	(*game)->m_vertical = 0;
	while (full_grid[(*game)->m_vertical])
		(*game)->m_vertical++;
	(*game)->m_vertical = ((*game)->m_vertical / 15) + 1;
	total = (*game)->m_horizontal * (*game)->m_vertical;
	return (total);
}

void	load_grid_segments(t_game **game)
{
	(*game)->m_mag = 1;
	(*game)->m_zoom = (*game)->grid_size / 4;
	(*game)->m_xset = 2;
	(*game)->m_yset = 2;
	load_full_grid(*game);
	(*game)->no_of_segments = count_segments(game, (*game)->map->full_grid);
	(*game)->map->segment
		= ft_calloc((*game)->no_of_segments + 1, sizeof(t_segment));
	fill_segments(game);
}
