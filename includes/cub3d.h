/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaija <ijaija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:26:59 by ijaija            #+#    #+#             */
/*   Updated: 2024/05/13 11:41:35 by ijaija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "./heap_control.h"
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h> // if printf not used remove it

# define S_WIDTH 1000
# define S_HEIGHT 1000

typedef struct s_parse_data
{
 char **map2d; // the map
 int  p_x;  // player pos (x)
 int  p_y;  // player pos (y)
 int  w_map;  // map width
 int  h_map;  // map height
}		t_parse_data;

#endif