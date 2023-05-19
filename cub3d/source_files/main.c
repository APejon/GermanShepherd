/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 01:12:32 by gchernys          #+#    #+#             */
/*   Updated: 2023/05/19 14:46:04 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	int		j;
	t_game	*game;

	j = -1;
	basic_error_check(argc, argv);
	game = malloc(sizeof(t_game));
	game->map = malloc(sizeof(t_map));
	ft_bzero(game->map, sizeof(t_map));
	if (game->map == NULL || game == NULL || malloc_map(game->map, argv[1]))
		return_error("Error\n Malloc error\n\n", game->map, game);
	load_map(game, game->map, argv[1]);
	load_grid(&game);
	game->win = malloc(sizeof(t_window));
	cub_init(game);
	mlx_hook(game->win->window, 17, 0, cub_close_x, &game);
	mlx_hook(game->win->window, 2, 0, cub_inputs, &game);
	mlx_loop(game->win->mlx);
	return (0);
}
