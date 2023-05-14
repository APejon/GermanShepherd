/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 01:12:32 by gchernys          #+#    #+#             */
/*   Updated: 2023/05/14 19:06:03 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	basic_error_check(argc, argv);
	game = malloc(sizeof(t_game));
	game->map = malloc(sizeof(t_map));
	ft_bzero(game->map, sizeof(t_map));
	if (game->map == NULL || game == NULL || malloc_map(game->map, argv[1]))
		return_error("Error\n Malloc error\n\n", game->map, game);
	load_map(game, game->map, argv[1]);
	game->win = malloc(sizeof(t_window));
	cub_window_init(&(game->win));
	return (0);
}
