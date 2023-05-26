/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:23:08 by amalbrei          #+#    #+#             */
/*   Updated: 2023/05/27 00:05:19 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUTS_H
# define INPUTS_H

/*----- cub_close_x -----*/
int		cub_close_x(t_game **game);

/*----- cub_free.c -----*/
void	cub_free_map(t_game **game);
void	cub_free_segments(t_game **game);

/*----- cub_inputs ------*/
void	cub_move_player(int key, t_game **game);
void	cub_enlarge_map(int key, t_game **game);
void	cub_change_map(int key, t_game **game);
void	cub_esc(int key, t_game **game);
int		cub_inputs(int key, t_game **game);

#endif