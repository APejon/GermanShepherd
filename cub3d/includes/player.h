/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 11:15:40 by amalbrei          #+#    #+#             */
/*   Updated: 2023/06/06 15:24:24 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

/*----- cub_calc_player.c -----*/
void	cub_player_init(t_game **game);
int		cub_subsequent_intersect(t_game **game, t_map *map, t_player *player);
int		cub_first_intersect(t_game **game, t_map *map, t_player *player);
void	cub_calc_player(t_game **game);

/*----- cub_find_intersect.c -----*/
void	cub_find_first_v(t_game **game, t_player *player);
void	cub_find_first_h(t_game **game, t_player *player);
void	cub_find_intersect(t_game **game, t_player *player, char strt_flag);

/*----- cub_find_player.c -----*/
int		cub_scan_player(t_game **game, char *line, int k);

/*----- cub_find_utils.c -----*/
void	cub_grid_mult(t_game **game, t_player *player);
void	cub_grid_division(t_game **game, t_player *player);

#endif