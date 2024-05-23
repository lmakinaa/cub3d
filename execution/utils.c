/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaija <ijaija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 21:43:23 by ijaija            #+#    #+#             */
/*   Updated: 2024/05/23 15:47:34 by ijaija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	vr(void)
{
	return (0);
}

// hadi 3ir katpushi limg flwindow
void	display_img(t_cub *mlx, int what_img)
{
	int			x;
	int			y;
	mlx_image_t	*img;

	if (what_img == MAIN)
		(1) && (x = 0, y = 0, img = mlx->img, vr());
	else if (what_img == MINIMAP)
		(1) && (x = 0, y = S_H - MINIMAP_H, img = mlx->minimap_img, vr());
	mlx_image_to_window(mlx->mlx_p, img, x, y);
}

// hadi katcree image w katinitialisiha
void	new_img(t_cub *mlx, int what_img, int clear_it)
{
	int			h;
	int			w;

	if (what_img == MAIN)
	{
		(1) && (h = S_H, w = S_W);
		mlx_delete_image(mlx->mlx_p, mlx->img);
		mlx->img = mlx_new_image(mlx->mlx_p, w, h);
	}
	else if (what_img == MINIMAP)
	{
		(1) && (h = MINIMAP_H, w = MINIMAP_W);
		mlx_delete_image(mlx->mlx_p, mlx->minimap_img);
		mlx->minimap_img = mlx_new_image(mlx->mlx_p, w, h);
	}
}
