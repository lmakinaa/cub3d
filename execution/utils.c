/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaija <ijaija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 21:43:23 by ijaija            #+#    #+#             */
/*   Updated: 2024/05/22 22:10:42 by ijaija           ###   ########.fr       */
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
