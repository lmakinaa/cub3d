/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaija <ijaija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 21:41:45 by ijaija            #+#    #+#             */
/*   Updated: 2024/05/23 02:40:03 by ijaija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_data	*init_data(void)
{
	t_data *res;

	res = heap_control(M_ALLOC, sizeof(t_data), 0, 1); // init the data structure
	res->map2d = heap_control(M_ALLOC, 10 * sizeof(char *), 0, 1); // init the map
	res->mlx = heap_control(M_ALLOC, sizeof(t_cub), 0, 1);
	res->map2d[0] = strdup("1111111111111111111111111"); //fill the map
	res->map2d[1] = strdup("1000000000000000000100001");
	res->map2d[2] = strdup("1001000000000P00000000001");
	res->map2d[3] = strdup("1001000000000000001000001");
	res->map2d[4] = strdup("1001000000000000001000001");
	res->map2d[5] = strdup("1001000000100000001000001");
	res->map2d[6] = strdup("1001000000000000001000001");
	res->map2d[7] = strdup("1001000000001000001000001");
	res->map2d[8] = strdup("1111111111111111111111111");
	res->map2d[9] = NULL;
	res->p_y = 3; // player y position in the map
	res->p_x = 14; // player x position in the map
	res->w_map = 25; // map width
	res->h_map = 9; // map height
	return (res); // return the data structure
}

void init_the_player(t_cub *mlx)
{
	mlx->p->x_pixel = mlx->data->p_x * TILE_SIZE + TILE_SIZE / 2; // player x position in pixels in the center of the tile
	mlx->p->y_pixel = mlx->data->p_y * TILE_SIZE + TILE_SIZE / 2; // player y position in pixels in the center of the tile
	mlx->p->mini_x_pixel = mlx->data->p_x * MINI_TILE_SIZE + MINI_TILE_SIZE / 2; // player x position in minimap
	mlx->p->mini_y_pixel = mlx->data->p_y * MINI_TILE_SIZE + MINI_TILE_SIZE / 2; // player y position in minimap
	mlx->p->fov_rd = (FOV * M_PI) / 180; // field of view in radians
	mlx->p->angle = M_PI; // player angle
}
