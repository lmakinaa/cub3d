/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaija <ijaija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:09:29 by ijaija            #+#    #+#             */
/*   Updated: 2024/05/23 15:48:35 by ijaija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

void	game_loop(void *m)
{
	t_cub *mlx;

	mlx = m;
	generate_minimap(mlx);
	display_img(mlx, MINIMAP);
}

void start_the_game(t_data *data)
{
	t_cub	*mlx;

	mlx = data->mlx;
	mlx->data = data;
	mlx->p = heap_control(M_ALLOC, sizeof(t_player), 0, 1);
	mlx->ray = heap_control(M_ALLOC, sizeof(t_ray), 0, 1);
	mlx->mlx_p = mlx_init(S_W, S_H, "cub3d", true);
	if (!mlx->mlx_p)
		exit_on_error("mlx_init() failed\n", 18);
	mlx->img = mlx_new_image(mlx->mlx_p, S_W, S_H);
	if (!mlx->img || (mlx_image_to_window(mlx->mlx_p, mlx->img, 0, 0) < 0))
		exit_on_error("mlx_new_image() failed\n", 23);
	mlx->minimap_img = mlx_new_image(mlx->mlx_p, MINIMAP_W + 50, MINIMAP_H + 50);
	if (!mlx->minimap_img || (mlx_image_to_window(mlx->mlx_p,
		mlx->minimap_img, 0, S_H - MINIMAP_H) < 0))
		exit_on_error("mlx_new_image() failed\n", 23);
	init_the_player(mlx);
	mlx_loop_hook(mlx->mlx_p, game_loop, mlx);
	//mlx_key_hook(mlx, key_hooks, mlx);
}

int main(void)
{
	t_data *data;

	data = init_data();
	start_the_game(data);

	mlx_loop(data->mlx->mlx_p);
	mlx_terminate(data->mlx->mlx_p);
	//heap_control(M_CLEAN, 0, 0, 0); // lmode dyal lclean 5asr 7alyan tangado
	return 0;
}


//int32_t	main(void)
//{

//	// MLX allows you to define its core behaviour before startup.
//	//mlx_set_setting(MLX_MAXIMIZED, true);
//	mlx_t* mlx = mlx_init(S_W, S_H, "42Balls", true);
//	//if (!mlx)
//	//	ft_error();

//	/* Do stuff */

//	// Create and display the image.
//	mlx_image_t* img = mlx_new_image(mlx, 256, 256);
//	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0));
//		//ft_error();

//	// Even after the image is being displayed, we can still modify the buffer.
//	mlx_put_pixel(img, 10, 10, 0xFF0F00FF);

//	// Register a hook and pass mlx as an optional param.
//	// NOTE: Do this before calling mlx_loop!
	
//	mlx_loop_hook(mlx, ft_hook, mlx);
//	mlx_loop(mlx);
//	mlx_terminate(mlx);
//	return (EXIT_SUCCESS);
//}