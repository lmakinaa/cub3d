/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaija <ijaija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 19:05:18 by ijaija            #+#    #+#             */
/*   Updated: 2024/05/22 22:20:50 by ijaija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

void	draw_minimap(t_mlx *mlx)
{
	char	**map;

	map = mlx->data->map2d;
	int i = -1;
	while (++i < MINIMAP_H)
	{
		int j = -1;
		while (++j < MINIMAP_W)
			pixel_put(mlx->minimap_img, j, i, 0xFF52);
	}
}

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
