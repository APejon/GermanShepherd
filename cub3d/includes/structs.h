/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 12:32:47 by amalbrei          #+#    #+#             */
/*   Updated: 2023/05/27 13:50:05 by amalbrei         ###   ########.fr       */
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
	double	deltax[2];
	double	deltay[2];
	double	signx;
	double	signy;
	double	x_step;
	double	y_step;
	double	swap;
	double	temp;
	double	x;
	double	y;
	double	p;
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
	double		x_grid;
	double		y_grid;
	double		x;
	double		y;
	char		dir;
}		t_player;

typedef struct s_segment
{
	char				**grid;
	int					player_found;
	struct s_segment	*next;
	struct s_segment	*north;
	struct s_segment	*south;
	struct s_segment	*east;
	struct s_segment	*west;
}	t_segment;

typedef struct s_map
{
	char			**map;
	char			**full_grid;
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
	t_segment		**segment;
	t_player		*player;
}		t_map;

typedef struct s_game
{
	int			m_zoom;
	int			m_mag;
	int			m_xset;
	int			m_yset;
	int			m_width;
	int			m_height;
	int			m_horizontal;
	int			m_vertical;
	int			no_of_segments;
	int			color;
	int			start;
	t_map		*map;
	t_window	*win;
}		t_game;

#endif