/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_find_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 20:42:56 by amalbrei          #+#    #+#             */
/*   Updated: 2023/05/27 00:07:03 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	cub_scan_player(t_game **game, char *line, int k)
{
	int		i;
	char	found;

	i = -1;
	found = 0;
	while (line[++i])
	{
		if (line[i] == 'N' || line[i] == 'S' || line[i] == 'E'
			|| line[i] == 'W')
			found = line[i];
	}
	if (found)
	{
		(*game)->map->player->x = ft_find_char(line, found);
		(*game)->map->player->y = k;
		(*game)->map->player->x_grid = ((*game)->map->player->x
				+ (*game)->m_xset) * (*game)->m_zoom
			+ ((*game)->m_zoom / 2);
		(*game)->map->player->y_grid = ((*game)->map->player->y
				+ (*game)->m_yset) * (*game)->m_zoom + ((*game)->m_zoom / 2);
		(*game)->map->player->dir = found;
		return (1);
	}
	return (0);
}
