/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_close_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:23:53 by amalbrei          #+#    #+#             */
/*   Updated: 2023/06/25 11:04:18 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	cub_no_clip(t_map *map, t_player *player, char **full_grid)
{
	if (full_grid[(int)player->y_pos / 64][(int)player->x_pos / 64] == 'x'
		|| player->fl_coll < 5 || player->fr_coll < 5
		|| player->bl_coll < 5 || player->br_coll < 5
		|| player->l_coll < 5 || player->r_coll < 5
		|| player->fl2_coll < 5 || player->fr2_coll < 5
		|| player->bl2_coll < 5 || player->br2_coll < 5
		|| player->y_pos / 64 < 1 || player->x_pos / 64 < 1
		|| player->y_pos / 64 > map->high - 1
		|| player->x_pos / 64 > map->wide - 2)
		return (1);
	return (0);
}

int	cub_close_x(t_game **game)
{
	mlx_clear_window((*game)->win->mlx, (*game)->win->window);
	cub_free_map(game);
	cub_free_segments(game);
	ft_free(&((*game)->map));
	ft_free(&((*game)->keys));
	ft_free(&((*game)->win->addr));
	ft_free(&((*game)->win));
	ft_free(&((*game)->player->verti_i));
	ft_free(&((*game)->player->horiz_i));
	ft_free(&((*game))->player);
	ft_free(&((*game)));
	exit(0);
}
