/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguiji <miguiji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 20:35:55 by hsobane           #+#    #+#             */
/*   Updated: 2024/05/23 17:44:51 by miguiji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

void	draw_line_low(mlx_image_t *img, t_point start, t_point end, int color)
{
	int	dx;
	int	dy;
	int	yi;
	int	d;
	int	y;
	int	x;

	dx = end.x - start.x;
	dy = end.y - start.y;
	yi = 1 - 2 * (dy < 0);
	d = 2 * dy * yi - dx;
	y = start.y;
	x = start.x;
	while (x <= end.x)
	{
		mlx_put_pixel(img, x, y, color);
		if (d > 0)
		{
			y += yi;
			d -= 2 * dx;
		}
		d += 2 * dy * yi;
		x++;
	}
}

void	draw_line_high(mlx_image_t *img, t_point start, t_point end, int color)
{
	int	dx;
	int	dy;
	int	xi;
	int	d;
	int	y;
	int	x;

	dx = end.x - start.x;
	dy = end.y - start.y;
	xi = 1 - 2 * (dx < 0);
	d = 2 * dx * xi - dy;
	y = start.y;
	x = start.x;
	while (y <= end.y)
	{
		mlx_put_pixel(img, x, y, color);
		if (d > 0)
		{
			x += xi;
			d -= 2 * dy;
		}
		d += 2 * dx * xi;
		y++;
	}
}

// bresenham algorithm
void	draw_line(mlx_image_t *img, t_line line, int color)
{
	if (abs(line.end.y - line.start.y) < abs(line.end.x - line.start.x))
	{
		if (line.start.x > line.end.x)
			draw_line_low(img, line.end, line.start, color);
		else
			draw_line_low(img, line.start, line.end, color);
	}
	else
	{
		if (line.start.y > line.end.y)
			draw_line_high(img, line.end, line.start, color);
		else
			draw_line_high(img, line.start, line.end, color);
	}
}

void swap_points(t_point *p1, t_point *p2)
{
	t_point temp;

	temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

double ft_slope(t_line line)
{
	int dx;
	int dy;

	dx = line.end.x - line.start.x;
	dy = line.end.y - line.start.y;
	if (dx == 0)
		return (INT_MAX);
	return ((double)dy / dx);
}

void ft_flip(t_line *line)
{
	int	temp;

	temp = line->start.x;
	line->start.x = line->start.y;
	line->start.y = temp;
	temp = line->end.x;
	line->end.x = line->end.y;
	line->end.y = temp;
}

double ft_rad(double angle)
{
	return (angle * M_PI / 180);
}
