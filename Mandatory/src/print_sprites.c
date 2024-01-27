/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sprites.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 09:22:27 by aaghla            #+#    #+#             */
/*   Updated: 2024/01/27 09:29:24 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_wall(t_data *data, int x, int y)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->wall, x, y);
}

void	put_walk(t_data *data, int x, int y)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->walk, x, y);
}

void	put_collect(t_data *data, int x, int y)
{
	put_walk(data, x, y);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->collect, x, y);
}

void	put_door(t_data *data, int x, int y, int state)
{
	if (state == 0)
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->door_c, x, y);
	else if (state == 1)
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->door_o, x, y);
}
