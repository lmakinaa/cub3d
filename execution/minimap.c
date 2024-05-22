/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaija <ijaija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 19:05:18 by ijaija            #+#    #+#             */
/*   Updated: 2024/05/22 21:52:57 by ijaija           ###   ########.fr       */
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

void	generate_minimap(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx_p, mlx->minimap_img.img_p);
	mlx->minimap_img.img_p = mlx_new_image(mlx->mlx_p, MINIMAP_W, MINIMAP_H); // create new image
	mlx->minimap_img.start_addr =  mlx_get_data_addr(mlx->minimap_img.img_p, &mlx->minimap_img.bpp, &mlx->minimap_img.line_size, &mlx->minimap_img.endian);
	draw_minimap(mlx);
}
