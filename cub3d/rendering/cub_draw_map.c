/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_draw_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 19:03:57 by amalbrei          #+#    #+#             */
/*   Updated: 2023/05/21 15:34:52 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../includes/cub3d.h"

// int	cub_end_of_line(char *line)
// {
// 	int	i;

// 	i = 0;
// 	while (line[i] == 'x')
// 		i++;
// 	if (line[i] == '\0')
// 		return (1);
// 	else
// 		return (0);
// }

// void	cub_draw_grid_extra(t_game *game, t_map *map, int x, int y)
// {
// 	if (y != 0 && map->grid[y][x] == 'x' && map->grid[y - 1][x] != 'x')
// 		cub_bressenham(x + game->m_xset, y + game->m_yset, game, 'x');
// 	if (x != 0 && map->grid[y][x] == 'x'
// 		&& map->grid[y][x - 1] != 'x')
// 		cub_bressenham(x + game->m_xset, y + game->m_yset, game, 'y');
// 	if (map->grid[y + 1] == NULL && map->grid[y][x] != 'x')
// 		cub_bressenham(x + game->m_xset, y + game->m_yset + 1, game, 'x');
// }

// void	cub_draw_grid(t_game *game, t_map *map)
// {
// 	int	x;
// 	int	y;

// 	game->color = 0x000000;
// 	y = 0;
// 	while (map->grid[y])
// 	{
// 		x = 0;
// 		while (map->grid[y][x] == 'x')
// 			x++;
// 		while (map->grid[y][x])
// 		{
// 			if (map->grid[y][x] != 'x')
// 			{
// 				cub_bressenham(x + game->m_xset, y + game->m_yset, game, 'x');
// 				cub_bressenham(x + game->m_xset, y + game->m_yset, game, 'y');
// 			}
// 			cub_draw_grid_extra(game, map, x, y);
// 			if (map->grid[y][x] == 'x' && cub_end_of_line(map->grid[y] + x))
// 				break ;
// 			x++;
// 		}
// 		cub_bressenham(x + game->m_xset, y + game->m_yset, game, 'y');
// 		y++;
// 	}
// }

// void	cub_draw_m_background(t_game *game, t_window *win)
// {
// 	win->addr->i_p = mlx_xpm_file_to_image(game->win->mlx,
// 			"textures/clouds.xpm", &(game->m_width), &(game->m_height));
// 	win->addr->ad = mlx_get_data_addr(win->addr->i_p, &(win->addr->pix_bi),
// 			&(win->addr->line_by), &win->addr->endian);
// }
