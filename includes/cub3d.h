/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaija <ijaija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:26:59 by ijaija            #+#    #+#             */
/*   Updated: 2024/05/21 17:28:07 by ijaija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "./heap_control.h"
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <mlx.h>
# include <string.h>
# include <stdio.h>

# define S_WIDTH 1000
# define S_HEIGHT 1000

typedef struct s_parse_data
{
	char	**map2d; // the map
	int		p_x;  // player pos (x)
	int		p_y;  // player pos (y)
	int		w_map;  // map width
	int		h_map;  // map height
}		t_parse_data;

# define S_W 1900 // screen width
# define S_H 1000 // screen height
# define TILE_SIZE 30 // tile size
# define FOV 60 // field of view
# define ROTATION_SPEED 0.045 // rotation speed
# define PLAYER_SPEED 4 // player speed

typedef struct s_player //the player structure
{
	int		player_x; // player x position in pixels
	int		player_y; // player y position in pixels
	double	angle; // player angle
	float	fov_rd; // field of view in radians
	int		rot; // rotation flag
	int		l_r; // left right flag
	int		u_d; // up down flag
}		t_player;

typedef struct s_ray //the ray structure
{
	double	ray_ngl; // ray angle
	double	distance; // distance to the wall
	int		flag;  // flag for the wall
}		t_ray;

typedef struct s_data //the data structure
{
	char			**map2d; // the map
	int				p_x;  // player x position in the map
	int				p_y;  // player y position in the map
	int				w_map;  // map width
	int				h_map;  // map height
	struct s_mlx	*mlx;
}		t_data;

typedef struct	s_mlx_img
{
	void	*img_p;
	char	*start_addr;
	int		bpp;
	int		line_size;
	int		endian;
}		t_img;

typedef struct s_mlx //the mlx structure
{
	t_img		img; // the image
	void		*win;
	void		*mlx_p; // the mlx pointer
	t_ray		*ray; // the ray structure
	t_data		*data; // the data structure
	t_player	*ply; // the player structure
} 		t_mlx;

#endif