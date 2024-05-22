/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaija <ijaija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 19:05:18 by ijaija            #+#    #+#             */
/*   Updated: 2024/05/22 22:47:27 by ijaija           ###   ########.fr       */
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
			else if (map[y][x] == '0')
				color = 0xFF000000;
			else if (map[y][x] == 'P')
				color = 0x0000FF00;
			draw_tile(mlx, x * MINI_TILE_SIZE, y * MINI_TILE_SIZE, color);
		}
	}
}

// hadi katcree image w katinitialisiha
void	new_img(t_mlx *mlx, int what_img)
{
	t_img	*img;
	int		h;
	int		w;

	if (what_img == MAIN)
		(1) && (img = &mlx->img, h = S_H, w = S_W);
	else if (what_img == MINIMAP)
		(1) && (img = &mlx->minimap_img, h = MINIMAP_H, w = MINIMAP_W);
	mlx_destroy_image(mlx->mlx_p, img->img_p);
	img->img_p = mlx_new_image(mlx->mlx_p, w, h); // create new image
	img->start_addr =  mlx_get_data_addr(img->img_p, &img->bpp, &img->line_size, &img->endian);
}

void	generate_minimap(t_mlx *mlx)
{
	new_img(mlx, MINIMAP);
	draw_minimap(mlx);
}
