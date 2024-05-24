/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaija <ijaija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 19:17:40 by ijaija            #+#    #+#             */
/*   Updated: 2024/05/24 02:26:52 by ijaija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

void cast_rays(t_cub *cub)
{
	int	col;

	cub->ray->ray_angle = cub->p->angle - (FOV / 2);
	for (int i = 0; i < NUM_RAYS; i++)
	{
		cub->ray->ray_angle += (FOV / MINIMAP_W);
		col++;
	}
}

// h_step