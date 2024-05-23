/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaija <ijaija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 19:05:18 by ijaija            #+#    #+#             */
/*   Updated: 2024/05/23 02:54:56 by ijaija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

void	draw_tile(t_cub *mlx, int x, int y, int color)
{
	int	i;
	int	j;

	i = -1;
	while (++i < MINI_TILE_SIZE)
	{
		j = -1;
		while (++j < MINI_TILE_SIZE)
			mlx_put_pixel(mlx->minimap_img, x + i, y + j, color);
	}
}

void	draw_minimap(t_cub *mlx)
{
	int		x;
	int		y;
	char	**map;
	int		color;

	map = mlx->data->map2d;
	y = -1;
	while (++y < mlx->data->h_map)
	{
		x = -1;
		while (++x < mlx->data->w_map)
		{
			if (map[y][x] == '1')
				color = 0xFF0F00FF;
			else if (map[y][x] == '0' || map[y][x] == 'P')
				color = 0xFF0F00FF;
			if (x == mlx->data->p_x && y == mlx->data->p_y)
				color = 0xFF0F00FF;
			//mlx_put_pixel(mlx->minimap_img, 5, 5, color);
			draw_tile(mlx, x * MINI_TILE_SIZE, y * MINI_TILE_SIZE, color);
		}
	}
}

void	generate_minimap(t_cub *mlx)
{
	//new_img(mlx, MINIMAP, 0);
	draw_minimap(mlx);
}
