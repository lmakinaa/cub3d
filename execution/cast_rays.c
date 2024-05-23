/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaija <ijaija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 19:17:40 by ijaija            #+#    #+#             */
/*   Updated: 2024/05/23 01:45:30 by ijaija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

float	map_angle(double angle)
{
	if (angle < 0)
		angle += (2 * M_PI);
	else if (angle > 0)
		angle -= (2 * M_PI);
	return (angle);
}

void cast_rays(t_cub *mlx)
{
	double h_inter;
	double v_inter;
	int  ray;

	ray = 0;
	mlx->ray->ray_angle = (M_PI / 2) - (FOV / 2);
	while (ray < S_W)
	{
		mlx->ray->flag_if_wall = 0;
		h_inter = (mlx->data->p_y / TILE_SIZE) * TILE_SIZE;
		v_inter = (mlx->data->p_x + (h_inter - mlx->data->p_y)) / tan(map_angle(mlx->ray->ray_angle));
		mlx->ray->ray_angle += FOV/S_W;
		ray++;
	}
	
}

// h_step