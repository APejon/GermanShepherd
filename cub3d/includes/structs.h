/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 12:32:47 by amalbrei          #+#    #+#             */
/*   Updated: 2023/06/23 16:22:49 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef enum e_error
{
	MALLOC_ERR = 1,
	PARSE_ERR,
}	t_error;

typedef enum e_side
{
	NORTH = 1,
	SOUTH,
	EAST,
	WEST,
}	t_side;

typedef struct s_keys {
	bool	esc;
	bool	w;
	bool	s;
	bool	a;
	bool	d;
	bool	u_arrow;
	bool	d_arrow;
	bool	l_arrow;
	bool	r_arrow;
	bool	shift;
	bool	m_switch;
	bool	m_player;
	bool	m_enlarge;
}	t_keys;

typedef struct s_bress {
	double	deltax[2];
	double	deltay[2];
	int		signx;
	int		signy;
	int		x_step;
	int		y_step;
	int		swap;
	int		temp;
	int		x;
	int		y;
	int		p;
	double	x_shift;
	double	y_shift;
	double	x_check;
	double	y_check;
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
	char	prot_flag;
	int		fov;
	int		height;
	int		up;
	char	dir;
	double	speed;
	double	p_angle;
	double	r_angle;
	double	rays;
	int		hit;
	int		side;
	double	x;
	double	y;
	double	x_pos;
	double	y_pos;
	double	x_m_grid;
	double	y_m_grid;
	int		x_shift;
	int		y_shift;
	double	*verti_i;
	double	*horiz_i;
	double	project_dis;
	double	verti_dis;
	double	horiz_dis;
	double	correct_dis;
	double	fl_coll;
	double	fr_coll;
	double	bl_coll;
	double	br_coll;
	double	l_coll;
	double	r_coll;
}		t_player;

typedef struct s_segment
{
	char				**grid;
	int					id;
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
}		t_map;

typedef struct s_game
{
	int			grid_size;
	int			m_zoom;
	int			m_mag;
	int			m_xset;
	int			m_yset;
	int			m_width;
	int			m_height;
	int			m_horizontal;
	int			m_vertical;
	int			no_of_segments;
	int			start;
	int			color;
	int			border_x;
	int			border_y;
	int			win_x;
	int			x_shift;
	int			y_shift;
	t_map		*map;
	t_player	*player;
	t_window	*win;
	t_keys		*keys;
}		t_game;

#endif
