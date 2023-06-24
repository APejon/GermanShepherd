/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_info_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 13:28:57 by amalbrei          #+#    #+#             */
/*   Updated: 2023/06/24 15:48:40 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	cub_comma_count(char *line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i])
	{
		if (line[i] == ',')
			j++;
		i++;
	}
	return (j);
}

int	cub_consec_newlines(t_map *map, char *str, char *line)
{
	if (map->check)
	{
		if (*(ft_strrchr(str, '\n') + 1) == '\0' && line[0] == '\n')
		{
			ft_free(&line);
			ft_free(&str);
			return (1);
		}
	}
	return (0);
}

int	cub_check_newlines(t_map *map, char *str, char *line)
{
	int	i;

	i = -1;
	if (line)
	{
		while (line[++i])
		{
			while (line[i] == '1')
				i++;
			if (line[i] == '\n' && i != 0)
				map->check = 1;
			else if (!map->check)
				break ;
			if (!line[i])
				break ;
		}
		if (cub_consec_newlines(map, str, line))
			return (1);
	}
	return (0);
}
