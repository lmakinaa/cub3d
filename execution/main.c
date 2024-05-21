/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaija <ijaija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:09:29 by ijaija            #+#    #+#             */
/*   Updated: 2024/05/21 19:44:03 by ijaija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

int game_loop(void *m)
{
	t_mlx *mlx;

	mlx = m; // cast to the mlx structure
	mlx_destroy_image(mlx->mlx_p, mlx->img.img_p); // delete the image
	mlx->img.img_p = mlx_new_image(mlx->mlx_p, S_W, S_H); // create new image
	// hook(mlx, 0, 0); // hook the player
	cast_rays(mlx); // cast the rays
	mlx_put_image_to_window(mlx->mlx_p, mlx->win, mlx->img.img_p, 0, 0); // put the image to the window
	return (0);
}

int	mlx_key(int k)
{
	return (k);
}

void init_the_player(t_mlx *mlx)
{
	mlx->p->player_x = mlx->data->p_x * TILE_SIZE + TILE_SIZE / 2; // player x position in pixels in the center of the tile
	mlx->p->player_y = mlx->data->p_y * TILE_SIZE + TILE_SIZE / 2; // player y position in pixels in the center of the tile
	mlx->p->fov_rd = (FOV * M_PI) / 180; // field of view in radians
	mlx->p->angle = M_PI; // player angle
}

void start_the_game(t_data *data)
{
	t_mlx	*mlx;

	mlx = data->mlx;
	mlx->data = data; // init the mlx structure
	mlx->p = calloc(1, sizeof(t_player)); // init the player structure i'm using calloc to initialize the variables to zero
	mlx->ray = calloc(1, sizeof(t_ray)); // init the ray structure
	mlx->mlx_p = mlx_init(); // init the mlx pointer and put a window to the screen
	mlx->win = mlx_new_window(mlx->mlx_p, S_W, S_H, "Cub3D");
	mlx->img.img_p = mlx_new_image(mlx->mlx_p, S_W, S_H);
	init_the_player(mlx); // init the player structure
	mlx_loop_hook(mlx->mlx_p, game_loop, mlx); // game loop continuously call a specified function to update the game state and render the frames.
	// mlx_key_hook(mlx->win, &mlx_key, &mlx); // key press and release
}

t_data	*init_argumet(void)
{
	t_data *res;

	res = heap_control(M_ALLOC, sizeof(t_data), 0, 1); // init the data structure
	res->map2d = heap_control(M_ALLOC, 10 * sizeof(char *), 0, 1); // init the map
	res->mlx = heap_control(M_ALLOC, sizeof(t_mlx), 0, 1);
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

int main(void)
{
	t_data *data;

	data = init_argumet(); // init the data structure
	start_the_game(data); // start the game
	mlx_loop(data->mlx->mlx_p); // mlx loop
	heap_control(M_CLEAN, 0, 0, 0);
	//clean_exit();
	return 0;
}
