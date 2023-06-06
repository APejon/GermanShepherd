/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 01:12:32 by gchernys          #+#    #+#             */
/*   Updated: 2023/06/06 14:20:08 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	int		j;
	t_game	*game;

	j = -1;
	basic_error_check(argc, argv);
	game = ft_calloc(1, sizeof(t_game));
	game->map = ft_calloc(1, sizeof(t_map));
	if (game->map == NULL || game == NULL || malloc_map(game->map, argv[1]))
		return_error("Error\n Malloc error\n\n", game->map, game);
	game->player = ft_calloc(1, sizeof(t_player));
	game->player->verti_i = ft_calloc(2, sizeof(double));
	game->player->horiz_i = ft_calloc(2, sizeof(double));
	load_map(game, game->map, argv[1]);
	game->win = ft_calloc(1, sizeof(t_window));
	cub_init(game);
	mlx_hook(game->win->window, 17, 0, cub_close_x, &game);
	mlx_hook(game->win->window, 2, 0, cub_inputs, &game);
	mlx_loop(game->win->mlx);
	return (0);
}
