/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaija <ijaija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 19:05:18 by ijaija            #+#    #+#             */
/*   Updated: 2024/05/23 00:14:12 by ijaija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

void	draw_tile(t_mlx *mlx, int x, int y, int color)
{
	int	i;
	int	j;

	i = -1;
	while (++i < MINI_TILE_SIZE)
	{
		j = -1;
		while (++j < MINI_TILE_SIZE)
			pixel_put(mlx->minimap_img, x + i, y + j, color);
	}
}

void	draw_minimap(t_mlx *mlx)
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
				color = 0x00FF0000;
			else if (map[y][x] == '0' || map[y][x] == 'P')
				color = 0;
			if (x == mlx->data->p_x && y == mlx->data->p_y)
				color = 0x0000FF00;
			draw_tile(mlx, x * MINI_TILE_SIZE, y * MINI_TILE_SIZE, color);
		}
	}
}

void	generate_minimap(t_mlx *mlx)
{
	new_img(mlx, MINIMAP, 0);
	draw_minimap(mlx);
}
