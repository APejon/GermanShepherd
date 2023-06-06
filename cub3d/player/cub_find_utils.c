/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_find_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 14:57:32 by amalbrei          #+#    #+#             */
/*   Updated: 2023/06/06 15:24:18 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	cub_grid_mult(t_game **game, t_player *player)
{
	if (player->verti_i[0] != -1)
		(*game)->player->verti_i[0] *= 64;
	if (player->verti_i[1] != -1)
		(*game)->player->verti_i[1] *= 64;
	if (player->horiz_i[0] != -1)
		(*game)->player->horiz_i[0] *= 64;
	if (player->horiz_i[1] != -1)
		(*game)->player->horiz_i[1] *= 64;
}

void	cub_grid_division(t_game **game, t_player *player)
{
	if (player->verti_i[0] != -1)
		(*game)->player->verti_i[0] /= 64;
	if (player->verti_i[1] != -1)
		(*game)->player->verti_i[1] /= 64;
	if (player->horiz_i[0] != -1)
		(*game)->player->horiz_i[0] /= 64;
	if (player->horiz_i[1] != -1)
		(*game)->player->horiz_i[1] /= 64;
}
