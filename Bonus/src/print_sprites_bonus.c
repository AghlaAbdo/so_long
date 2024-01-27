/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sprites_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 09:22:27 by aaghla            #+#    #+#             */
/*   Updated: 2024/01/27 09:41:48 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	print_textures(char *map, t_data *data, int *y)
{
	int	x;

	x = 0;
	while (map[x])
	{
		if (map[x] == '1')
			put_wall(data, x * 48, *y * 48);
		else if (map[x] == '0' || map[x] == 'P')
			put_walk(data, x * 48, *y * 48);
		else if (map[x] == 'C')
			put_collect(data, x * 48, *y * 48);
		else if (map[x] == 'E')
		{
			data->map_data.exit_x = x * 48;
			data->map_data.exit_y = *y * 48;
			put_door(data, x * 48, *y * 48, 0);
		}
		x++;
	}
}

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
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->door_c, x, y);
	else if (state == 1)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->door_o, x, y);
}
