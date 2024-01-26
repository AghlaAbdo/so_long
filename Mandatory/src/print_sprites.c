/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sprites.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 09:22:27 by aaghla            #+#    #+#             */
/*   Updated: 2024/01/25 18:43:55 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	print_textures(char *map, t_data *data, int	*y)
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
	int		w;
	int		h;

	if (state == 0)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->door, x, y);
	else if (state == 1)
	{
		mlx_destroy_image(data->mlx_ptr, data->door);
		data->door = mlx_xpm_file_to_image(data->mlx_ptr, DOOR_OPEN, &w, &h);
		if (!data->door)
		{
			clear_map_arr(data->map_data.map);
			force_exit("Error\nDonn't have access to resources\n");
		}
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->door, x, y);
	}
}
