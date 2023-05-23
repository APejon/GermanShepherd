/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_find_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 20:42:56 by amalbrei          #+#    #+#             */
/*   Updated: 2023/05/22 20:50:47 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	cub_scan_player(char *line)
{
	if (ft_strchr(line, 'N') || ft_strchr(line, 'S') || ft_strchr(line, 'E')
		|| ft_strchr(line, 'W'))
		return (1);
	return (0);
}
