/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaija <ijaija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:09:29 by ijaija            #+#    #+#             */
/*   Updated: 2024/05/24 01:28:55 by ijaija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

void	game_loop(void *m)
{
	t_cub *cub;
	int tmp1;
	int tmp2;

	cub = m;
	update_vars(cub);
	generate_minimap(cub);
	display_img(cub, MINIMAP);
}

void start_the_game(t_data *data)
{
	t_cub	*cub;

	cub = data->cub;
	cub->data = data;
	cub->p = heap_control(M_ALLOC, sizeof(t_player), 0, 1);
	cub->ray = heap_control(M_ALLOC, sizeof(t_ray), 0, 1);
	cub->mlx_p = mlx_init(S_W, S_H, "cub3d", true);
	if (!cub->mlx_p)
		exit_on_error("mlx_init() failed\n", 18);
	cub->img = mlx_new_image(cub->mlx_p, S_W, S_H);
	if (!cub->img || (mlx_image_to_window(cub->mlx_p, cub->img, 0, 0) < 0))
		exit_on_error("mlx_new_image() failed\n", 23);
	cub->minimap_img = mlx_new_image(cub->mlx_p, MINIMAP_W, MINIMAP_H);
	if (!cub->minimap_img || (mlx_image_to_window(cub->mlx_p,
		cub->minimap_img, 0, 0) < 0))
		exit_on_error("mlx_new_image() failed\n", 23);
	init_the_player(cub);
	mlx_key_hook(cub->mlx_p, key_hooks, cub);
	mlx_loop_hook(cub->mlx_p, game_loop, cub);
}

int main(void)
{
	t_data *data;

	data = init_data();
	start_the_game(data);

	mlx_loop(data->cub->mlx_p);
	mlx_terminate(data->cub->mlx_p);
	heap_control(M_CLEAN, 0, 0, 0);
	return 0;
}
