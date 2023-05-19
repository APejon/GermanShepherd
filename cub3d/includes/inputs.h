/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:23:08 by amalbrei          #+#    #+#             */
/*   Updated: 2023/05/17 16:05:33 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUTS_H
# define INPUTS_H

/*----- cub_close_x -----*/
int		cub_close_x(t_game **game);

/*----- cub_inputs ------*/
void	cub_esc(int key, t_game **game);
int		cub_inputs(int key, t_game **game);

#endif