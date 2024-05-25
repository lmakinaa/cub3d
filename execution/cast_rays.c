/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguiji <miguiji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 19:17:40 by ijaija            #+#    #+#             */
/*   Updated: 2024/05/25 01:17:17 by ijaija           ###   ########.fr       */
/*   Updated: 2024/05/25 00:50:21 by miguiji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

void draw_slice(t_cub *cub, int col, double ray_length)
{
    // Calculate the wall height
    int wall_height = (int)(S_H / ray_length);

    // Calculate the start and end positions for the wall slice
    int start = (S_H / 2) - (wall_height / 2);
    start = start < 0 ? 0 : start;
    int end = (S_H / 2) + (wall_height / 2);
    end = end > S_H ? S_H : end;

    // Draw the ceiling, wall, and floor
    for (int y = 0; y < S_H; y++)
    {
        if (y < start)
        {
            // Draw the ceiling
            mlx_put_pixel(cub->img, col, y, get_rgba(255, 255, 255, 255)); // White color
        }
        else if (y >= start && y < end)
        {
            // Draw the wall
            mlx_put_pixel(cub->img, col, y, get_rgba(0, 0, 255, 255)); // Blue color
        }
        else
        {
            // Draw the floor
            mlx_put_pixel(cub->img, col, y, get_rgba(128, 128, 128, 255)); // Gray color
        }
    }
}
void cast_rays(t_cub *cub, int x, int y)
{
	int	col;

	cub->ray->ray_angle = cub->p->angle - (cub->p->fov_rd / 2);
	col = -1;
	while (++col < N_RAYS)
	{
		double ray_x = 0;
        double ray_y = 0;
		while (1)
		{
			ray_x += cos(cub->ray->ray_angle) * 0.1;
            ray_y += sin(cub->ray->ray_angle) * 0.1;
            int var_x = (x + ray_x) / TILE_SIZE;
            int var_y = (y + ray_y) / TILE_SIZE;
			if (cub->data->map2d[var_y][var_x] != '1')
                continue;
            else
                break;
		}
		draw_line(cub, x, y,
		x + ray_x,
		y + ray_y,
		get_rgba(0, 0, 255, 255));
		draw_slice(cub, col, sqrt(ray_x * ray_x + ray_y * ray_y));
		cub->ray->ray_angle += 0.005 * (M_PI / 180.);
	}
}
