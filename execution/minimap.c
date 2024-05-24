/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguiji <miguiji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 19:05:18 by ijaija            #+#    #+#             */
/*   Updated: 2024/05/24 02:26:30 by miguiji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

void	draw_tile(t_cub *cub, int x, int y, int color)
{
	int	i;
	int	j;

	i = -1;
	while (++i < MINI_TILE_SIZE)
	{
		j = -1;
		while (++j < MINI_TILE_SIZE)
			mlx_put_pixel(cub->minimap_img, x + i, y + j, color);
	}
}

int major(double a) {
    return (int)ceil(a);
}

void	draw_mini_player(t_cub *cub, int x, int y, int color)
{
    int	i;
    int	j;
    int	var_x;
    int	var_y;
    i = -1;
    while (++i < MINI_TILE_SIZE / 2)
    {
        j = -1;
        while (++j < MINI_TILE_SIZE / 2)
            mlx_put_pixel(cub->minimap_img, x + i, y + j, color);
    }
    x += MINI_TILE_SIZE / 4;
    y += MINI_TILE_SIZE / 4;
    double ang = -M_PI/6;
    while(ang <= M_PI/6)
    {
        double ray_x = 0;
        double ray_y = 0;
        while(1)
        {
            ray_x += cos(cub->p->angle + ang) * 0.1;
            ray_y += sin(cub->p->angle + ang) * 0.1;
            var_x = (x + ray_x) / TILE_SIZE;
            var_y = (y + ray_y) / TILE_SIZE;
            if (cub->data->map2d[var_y][var_x] != '1')
                continue;
            else
                break;
        }
        draw_line(cub, x, y, x + ray_x, y + ray_y, color);
        ang += 0.01;
    }
}
void	draw_minimap(t_cub *cub)
{
	int		x;
	int		y;
	char	**map;
	int		color;

	map = cub->data->map2d;
	y = -1;
	while (++y < cub->data->h_map)
	{
		x = -1;
		while (++x < cub->data->w_map)
		{
			if (map[y][x] == '1')
				color = 0xFF0F00FF;
			else if (map[y][x] == '0' || map[y][x] == 'P')
				color = C_TRANSPARENT;
			draw_tile(cub, x * MINI_TILE_SIZE, y * MINI_TILE_SIZE, color);
		}
	}
	draw_mini_player(cub, cub->p->mini_x_pixel, cub->p->mini_y_pixel, get_rgba(0, 0, 255, 255));
	
}

void	generate_minimap(t_cub *cub)
{
	new_img(cub, MINIMAP);
	draw_minimap(cub);
}
