/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_find_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 20:42:56 by amalbrei          #+#    #+#             */
/*   Updated: 2023/05/28 17:24:24 by amalbrei         ###   ########.fr       */
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
		(*game)->player->x = ft_find_char(line, found);
		(*game)->player->y = k;
		(*game)->player->x_m_grid = ((*game)->player->x
				+ (double)(*game)->m_xset) * (double)(*game)->m_zoom
			+ ((double)(*game)->m_zoom / 2) + 1;
		(*game)->player->y_m_grid = ((*game)->player->y
				+ (double)(*game)->m_yset) * (double)(*game)->m_zoom
			+ ((double)(*game)->m_zoom / 2);
		(*game)->player->dir = found;
		return (1);
	}
	return (0);
}
