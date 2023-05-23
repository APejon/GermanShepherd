/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   segmentation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 14:19:41 by amalbrei          #+#    #+#             */
/*   Updated: 2023/05/22 21:01:40 by amalbrei         ###   ########.fr       */
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
	int	no_of_segments;

	load_full_grid(*game);
	no_of_segments = count_segments(game, (*game)->map->full_grid);
	(*game)->map->segment = ft_calloc(no_of_segments + 1, sizeof(t_segment));
	fill_segments(game, no_of_segments);
}

	// printf("%d total number of segments\n", total);
	// int	i = -1;
	// while ((*game)->map->full_grid[++i])
	// 	printf("%s\n", (*game)->map->full_grid[i]);
	// printf("%d m_horizontal %d m_vertical\n", (*game)->m_horizontal, (*game)->m_vertical);