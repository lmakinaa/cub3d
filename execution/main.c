/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaija <ijaija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:09:29 by ijaija            #+#    #+#             */
/*   Updated: 2024/05/22 21:53:55 by ijaija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

int game_loop(void *m)
{
	t_mlx *mlx;

	mlx = m;
	generate_minimap(mlx);
	display_img(mlx, MINIMAP);
	return (0);
}

void start_the_game(t_data *data)
{
	t_mlx	*mlx;

	mlx = data->mlx;
	mlx->data = data;
	mlx->p = heap_control(M_ALLOC, sizeof(t_player), 0, 1);
	mlx->ray = heap_control(M_ALLOC, sizeof(t_ray), 0, 1);
	mlx->mlx_p = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx_p, S_W, S_H, "Cub3D");
	mlx->img.img_p = mlx_new_image(mlx->mlx_p, S_W, S_H);
	mlx->minimap_img.img_p = mlx_new_image(mlx->mlx_p, MINIMAP_W, MINIMAP_H);
	//init_the_player(mlx); // init the player structure
	mlx_loop_hook(mlx->mlx_p, game_loop, mlx);
}

int main(void)
{
	t_data *data;

	data = init_data();
	start_the_game(data);
	mlx_loop(data->mlx->mlx_p);
	heap_control(M_CLEAN, 0, 0, 0);
	return 0;
}
