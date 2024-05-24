/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaija <ijaija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 19:17:40 by ijaija            #+#    #+#             */
/*   Updated: 2024/05/24 17:04:00 by ijaija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

void cast_rays(t_cub *cub, int x, int y)
{
	int	col;

	cub->ray->ray_angle = cub->p->angle - (cub->p->fov_rd / 2);
	for (int i = 0; i < cub->ray->n_rays; i++)
	{
		draw_line(cub, x, y,
		x + cos(cub->ray->ray_angle) * 0.1,
		y + sin(cub->ray->ray_angle) * 0.1,
		get_rgba(0, 0, 255, 255));

		cub->ray->ray_angle += (cub->p->fov_rd / cub->ray->n_rays);
		col++;
	}
}

