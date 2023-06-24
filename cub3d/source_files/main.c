/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 01:12:32 by gchernys          #+#    #+#             */
/*   Updated: 2023/06/24 19:01:27 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	cub_mlx_keys(t_game *game)
{
	game->keys = ft_calloc(1, sizeof(t_keys));
	mlx_hook(game->win->window, 17, 0, cub_close_x, &game);
	mlx_hook(game->win->window, 2, 0, cub_key_press, &game);
	mlx_hook(game->win->window, 3, 0, cub_key_release, &game);
	mlx_loop_hook(game->win->mlx, cub_inputs, &game);
	mlx_loop(game->win->mlx);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	basic_error_check(argc, argv);
	game = ft_calloc(1, sizeof(t_game));
	game->grid_size = 64;
	if (!game)
	{
		write(2, "Error\n Malloc error\n", 21);
		return (1);
	}
	game->map = ft_calloc(1, sizeof(t_map));
	if (!game->map)
	{
		ft_free(&game);
		write(2, "Error\n Malloc error\n", 21);
		return (1);
	}
	if (malloc_map(game->map, argv[1]))
		return_error("Error\n Malloc error\n\n", game->map, game);
	game->map->check = 0;
	load_map(game, game->map, argv[1]);
	cub_init(game);
	cub_mlx_keys(game);
	return (0);
}
