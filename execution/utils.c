/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaija <ijaija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 21:43:23 by ijaija            #+#    #+#             */
/*   Updated: 2024/05/23 00:14:06 by ijaija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	vr(void)
{
	return (0);
}

// hadi 3ir katpushi limg flwindow
void	display_img(t_mlx *mlx, int what_img)
{
	int		x;
	int		y;
	void	*img;

	if (what_img == MAIN)
		(1) && (x = 0, y = 0, img = mlx->img.img_p, vr());
	else if (what_img == MINIMAP)
		(1) && (x = 0, y = S_H - MINIMAP_H, img = mlx->minimap_img.img_p, vr());
	mlx_put_image_to_window(mlx->mlx_p, mlx->win, img, x, y);
}

void	pixel_put(t_img img, int x, int y, unsigned int color)
{
	int		offset;
	char	*dst;

	offset = (y * img.line_size) + (x * (img.bpp / 8));
	dst = &img.start_addr[offset];
	*(unsigned int *) dst = color;
}

// needs some fix
void	clear_image(t_img *img, int h, int w)
{
	int	x;
	int	y;

	y = -1;
	while (++y < h)
	{
		x = -1;
		while (++x < w)
			pixel_put(*img, x, y, 0);
	}
}

// hadi katcree image w katinitialisiha
void	new_img(t_mlx *mlx, int what_img, int clear_it)
{
	t_img	*img;
	int		h;
	int		w;

	if (what_img == MAIN)
		(1) && (img = &mlx->img, h = S_H, w = S_W);
	else if (what_img == MINIMAP)
		(1) && (img = &mlx->minimap_img, h = MINIMAP_H, w = MINIMAP_W);
	mlx_destroy_image(mlx->mlx_p, img->img_p);
	img->img_p = mlx_new_image(mlx->mlx_p, w, h);
	img->start_addr =  mlx_get_data_addr(img->img_p, &img->bpp, &img->line_size, &img->endian);
	if (clear_it)
		clear_image(img, h, w);
}
