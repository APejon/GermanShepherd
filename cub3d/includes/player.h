/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 11:15:40 by amalbrei          #+#    #+#             */
/*   Updated: 2023/05/28 20:51:14 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

/*----- cub_calc_player.c -----*/
void	cub_player_init(t_game **game);
int		cub_first_intersect(t_game **game, t_map *map, t_player *player);
void	cub_calc_player(t_game **game);

/*----- cub_find_player.c -----*/
int		cub_scan_player(t_game **game, char *line, int k);

#endif