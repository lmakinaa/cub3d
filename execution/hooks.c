/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaija <ijaija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 23:11:48 by ijaija            #+#    #+#             */
/*   Updated: 2024/05/23 00:07:42 by ijaija           ###   ########.fr       */
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

/*
* 124 = →
* 123 = ←
* 126 = ↑
* 125 = ↓
*/
int	key_hooks(int k, t_mlx *mlx)
{
	if (k == 124 && is_position_valid(mlx->data, 'R'))
		mlx->data->p_x++;
	else if (k == 123 && is_position_valid(mlx->data, 'L'))
		mlx->data->p_x--;
	else if (k == 126 && is_position_valid(mlx->data, 'U'))
		mlx->data->p_y--;
	else if (k == 125 && is_position_valid(mlx->data, 'D'))
		mlx->data->p_y++;
	return (0);
}
