/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 11:15:59 by amalbrei          #+#    #+#             */
/*   Updated: 2023/05/26 23:59:00 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERING_H
# define RENDERING_H

/*----- cub_bressenham -----*/
void	my_mlx_pixel_put(t_game *game, int x, int y);
void	cub_bressenham_decision(t_game *game, t_bress *bress, int i);
void	cub_bressenham_frag(t_game *game, t_bress *bress, char *flag);
void	cub_bressenham(int x, int y, t_game *game, char *flag);

/*----- cub_draw_ui -----*/
void	cub_draw_outline(t_game *game, t_bress bress);
void	cub_draw_cursor(t_game *game, t_player *player);
void	cub_turn_transparent(t_game *game, t_window *win, char flag);
void	cub_draw_ui(t_game *game);

/*----- cub_draw_map -----*/
void	cub_print_m_info(t_game *game);
void	cub_draw_grid_extra(t_game *game, char **grid, int x, int y);
int		cub_end_of_line(char *line);
void	cub_draw_grid(t_game *game, char **grid);
void	cub_draw_m_background(t_game *game, t_window *win);

#endif