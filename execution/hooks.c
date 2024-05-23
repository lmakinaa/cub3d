/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaija <ijaija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 23:11:48 by ijaija            #+#    #+#             */
/*   Updated: 2024/05/23 16:33:43 by ijaija           ###   ########.fr       */
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
void	key_hooks(mlx_key_data_t k, void *m)
{
	t_cub	*cub;

	cub = m;
	if (k.key == MLX_KEY_RIGHT && is_position_valid(cub->data, 'R'))
		cub->data->p_x++;
	else if (k.key == MLX_KEY_LEFT && is_position_valid(cub->data, 'L'))
		cub->data->p_x--;
	else if (k.key == MLX_KEY_UP && is_position_valid(cub->data, 'U'))
		cub->data->p_y--;
	else if (k.key == MLX_KEY_DOWN && is_position_valid(cub->data, 'D'))
		cub->data->p_y++;
}
