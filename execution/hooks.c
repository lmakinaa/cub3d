/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaija <ijaija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 23:11:48 by ijaija            #+#    #+#             */
/*   Updated: 2024/05/23 16:52:32 by ijaija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_position_valid(t_data *data, char direction)
{
	if (direction == 'L')
	{
		if (data->map2d[data->p_y][data->p_x - 1] == '1')
			return (0);
	}
	else if (direction == 'R')
	{
		if (data->map2d[data->p_y][data->p_x + 1] == '1')
			return (0);
	}
	else if (direction == 'D')
	{
		if (data->map2d[data->p_y + 1][data->p_x] == '1')
			return (0);
	}
	else if (direction == 'U')
	{
		if (data->map2d[data->p_y - 1][data->p_x] == '1')
			return (0);
	}
	return (1);
}

void	arrow_press(t_cub *cub, int d)
{
	if (d == 'R')
		(is_position_valid(cub->data, 'R')) && (cub->data->p_x++);
	else if (d == 'L')
		(is_position_valid(cub->data, 'L')) && (cub->data->p_x--);
	else if (d == 'U')
		(is_position_valid(cub->data, 'U')) && (cub->data->p_y--);
	else if (d == 'D')
		(is_position_valid(cub->data, 'D')) && (cub->data->p_y++);
}

void	key_press(mlx_key_data_t *k, t_cub *cub, void (*f)(t_cub *cub, int d))
{
	if (k->key == MLX_KEY_RIGHT)
		f(cub, 'R');
	else if (k->key == MLX_KEY_LEFT)
		f(cub, 'L');
	else if (k->key == MLX_KEY_UP)
		f(cub, 'U');
	else if (k->key == MLX_KEY_DOWN)
		f(cub, 'D');
}

void	key_hooks(mlx_key_data_t k, void *m)
{
	t_cub	*cub;

	cub = m;
	if (k.action == MLX_PRESS)
		key_press(&k, cub, arrow_press);
}
