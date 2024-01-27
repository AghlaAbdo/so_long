/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:54:48 by aaghla            #+#    #+#             */
/*   Updated: 2024/01/27 10:31:09 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	create_map(char **map, t_data *data)
{
	int	y;
	int	x;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == '1')
				put_wall(data, x * 48, y * 48);
			else if (map[y][x] == '0' || map[y][x] == 'P')
				put_walk(data, x * 48, y * 48);
			else if (map[y][x] == 'C')
				put_collect(data, x * 48, y * 48);
			else if (map[y][x] == 'E')
			{
				data->map_data.exit_x = x * 48;
				data->map_data.exit_y = y * 48;
				put_door(data, x * 48, y * 48, 0);
			}
		}
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->p_frm_r, data->plr_x, data->plr_y);
}

int	close_window(t_data *data)
{
	my_destroy_imgs(data, (void *[]){data->wall, data->walk,
		data->collect, data->door_c, data->door_o,
		data->p_frm_r, data->p_frm_l}, 7);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	clear_map_arr(data->map_data.map);
	exit(0);
	return (0);
}

int	close_exit(t_data *data, char *err)
{
	ft_putstr_fd(err, 1);
	my_destroy_imgs(data, (void *[]){data->wall, data->walk,
		data->collect, data->door_c, data->door_o,
		data->p_frm_r, data->p_frm_l}, 7);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	clear_map_arr(data->map_data.map);
	exit(0);
	return (0);
}

int	force_exit(char *str, char *err)
{
	if (str)
		free(str);
	ft_putstr_fd(err, 2);
	exit(1);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc != 2)
		force_exit(NULL, "Error\nInvalide number of arguments\n");
	data_init(&data);
	data.map_data.map = handle_map(argv[1], &data);
	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr)
		data.win_ptr = mlx_new_window(data.mlx_ptr,
				(data.win_x) * 48, data.win_y * 48, "so_long");
	if (!data.mlx_ptr || !data.win_ptr)
	{
		clear_map_arr(data.map_data.map);
		force_exit(NULL, "Error\nCan't create a window\n");
	}
	init_imgs(&data);
	create_map(data.map_data.map, &data);
	mlx_hook(data.win_ptr, 2, 0, &move_it, &data);
	mlx_hook(data.win_ptr, 17, 0, &close_window, &data);
	mlx_loop(data.mlx_ptr);
}
