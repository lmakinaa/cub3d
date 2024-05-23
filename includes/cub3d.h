/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaija <ijaija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:26:59 by ijaija            #+#    #+#             */
/*   Updated: 2024/05/23 15:59:16 by ijaija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "./heap_control.h"
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "MLX42.h"
# include <string.h>
# include <stdio.h>

# define MAIN 0
# define MINIMAP 1

# define C_TRANSPARENT 0xFF000000

# define S_W 1900
# define S_H 1000
# define MINIMAP_H 180
# define MINIMAP_W 300
# define TILE_SIZE 32
# define MINI_TILE_SIZE 10
# define FOV 60
# define ROTATION_SPEED 0.045
# define PLAYER_SPEED 4

typedef struct s_player
{
	int		x_pixel; // player x position in pixels
	int		y_pixel; // player y position in pixels
	int		mini_x_pixel; // player x position in pixels
	int		mini_y_pixel; // player y position in pixels
	double	angle; // player angle
	float	fov_rd; // field of view in radians
	int		rot; // rotation flag
	int		l_r; // left right flag
	int		u_d; // up down flag
}		t_player;

typedef struct s_ray
{
	double	ray_angle;
	double	distance_to_wall;
	int		flag_if_wall;
}		t_ray;

typedef struct s_data
{
	char			**map2d;
	int				p_x;
	int				p_y;
	int				w_map;
	int				h_map;
	struct s_mlx	*mlx;
}		t_data;

typedef struct s_mlx
{
	mlx_image_t		*img;
	mlx_image_t		*minimap_img;
	mlx_t			*mlx_p;
	t_ray			*ray;
	t_data			*data;
	t_player		*p; // the player structure
} 		t_cub;

void 			cast_rays(t_cub *mlx);
void			draw_minimap(t_cub *mlx);
void			display_img(t_cub *mlx, int what_img);
void			generate_minimap(t_cub *mlx);
t_data			*init_data(void);
void			init_the_player(t_cub *mlx);
void			new_img(t_cub *mlx, int what_img, int clear_it);
void			key_hooks(mlx_key_data_t k, void *m);
void 			game_loop(void *m);

#endif