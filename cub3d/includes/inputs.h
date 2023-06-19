/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:23:08 by amalbrei          #+#    #+#             */
/*   Updated: 2023/06/19 19:27:01 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUTS_H
# define INPUTS_H

/*----- cub_close_x.c -----*/
int		cub_close_x(t_game **game);

/*----- cub_free.c -----*/
void	cub_free_map(t_game **game);
void	cub_free_segments(t_game **game);

/*----- cub_inputs_utils.c -----*/
void	cub_undo_cont2(t_game **game, t_player *player);
void	cub_undo_cont(t_game **game, t_player *player);
void	cub_undo(t_game **game, t_map *map, t_player *player);

/*----- cub_inputs.c ------*/
void	cub_change_speed(t_game **game);
void	cub_turn_player(t_game **game);
void	cub_move_player(t_game **game, t_player *player);
int		cub_inputs(t_game **game);

/*----- cub_press.c -----*/
void	cub_esc(t_game **game);
void	cub_change_map(t_game **game);
void	cub_movement(int key, t_game **game);
int		cub_key_press(int key, t_game **game);
int		cub_key_release(int key, t_game **game);

#endif