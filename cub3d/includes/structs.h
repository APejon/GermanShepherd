/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 12:32:47 by amalbrei          #+#    #+#             */
/*   Updated: 2023/05/19 18:58:26 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef enum e_error
{
	MALLOC_ERR = 1,
	PARSE_ERR,
}	t_error;

typedef struct s_bress {
	int	deltax[2];
	int	deltay[2];
	int	sign1;
	int	sign2;
	int	x_step;
	int	y_step;
	int	swap;
	int	temp;
	int	x;
	int	y;
	int	p;
}	t_bress;

typedef struct s_addr {
	void	*i_p;
	char	*ad;
	int		pix_bi;
	int		line_by;
	int		endian;
}	t_addr;

typedef struct s_window{
	void	*mlx;
	void	*window;
	int		window_h;
	int		window_w;
	t_addr	*addr;
}	t_window;

typedef struct s_player
{
	int		x;
	int		y;
	char	dir;
}		t_player;

typedef struct s_map
{
	char			**map;
	char			**grid;
	unsigned int	floor_color;
	unsigned int	ceiling_color;
	char			*floor;
	char			*cil;
	int				wide;
	int				high;
	char			*north;
	char			*south;
	char			*west;
	char			*east;
	t_player		*player;
}		t_map;

typedef struct s_game
{
	int			m_zoom;
	int			m_xset;
	int			m_yset;
	int			color;
	t_map		*map;
	t_window	*win;
}		t_game;

#endif