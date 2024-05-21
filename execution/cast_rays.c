/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaija <ijaija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 19:17:40 by ijaija            #+#    #+#             */
/*   Updated: 2024/05/21 23:57:36 by ijaija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

float	map_angle(double angle)
{
	if (angle < 0)
		angle += M_PI;
	else if (angle > 0)
		angle -= M_PI;
	return (angle);
}

void cast_rays(t_mlx *mlx)
{
	double h_inter;
	double v_inter;
	int  ray;

	ray = 0;
	mlx->ray->ray_angle = (M_PI / 2) - (FOV/2);
	while (ray < S_W)
	{
		mlx->ray->flag_if_wall = 0;
		
		mlx->ray->ray_angle += FOV/S_W;
		ray++;
	}
	
}

