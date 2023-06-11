/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_find_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 14:57:32 by amalbrei          #+#    #+#             */
/*   Updated: 2023/06/11 16:39:39 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	cub_grid_mult_verti(t_game **game, t_player *player)
{
	if (player->verti_i[0] >= 0.0)
		(*game)->player->verti_i[0] *= 64.0;
	if (player->verti_i[1] >= 0.0)
		(*game)->player->verti_i[1] *= 64.0;
}

void	cub_grid_mult_hori(t_game **game, t_player *player)
{
	if (player->horiz_i[0] >= 0.0)
		(*game)->player->horiz_i[0] *= 64.0;
	if (player->horiz_i[1] >= 0.0)
		(*game)->player->horiz_i[1] *= 64.0;
}

void	cub_grid_div_verti(t_game **game, t_player *player)
{
	if (player->verti_i[0] >= 0.0)
		(*game)->player->verti_i[0] /= 64.0;
	if (player->verti_i[1] >= 0.0)
		(*game)->player->verti_i[1] /= 64.0;
}

void	cub_grid_div_hori(t_game **game, t_player *player)
{
	if (player->horiz_i[0] >= 0.0)
		(*game)->player->horiz_i[0] /= 64.0;
	if (player->horiz_i[1] >= 0.0)
		(*game)->player->horiz_i[1] /= 64.0;
}
