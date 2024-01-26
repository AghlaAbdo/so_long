/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:54:48 by aaghla            #+#    #+#             */
/*   Updated: 2024/01/25 18:43:23 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_map(char **map, t_data *data)
{
	int	y;
	int	w;
	int	h;

	data->wall = mlx_xpm_file_to_image(data->mlx_ptr, WALL, &w, &h);
	data->walk = mlx_xpm_file_to_image(data->mlx_ptr, WALK, &w, &h);
	data->collect = mlx_xpm_file_to_image(data->mlx_ptr, COLLECT, &w, &h);
	data->door = mlx_xpm_file_to_image(data->mlx_ptr, DOOR_CLOSE, &w, &h);
	check_valid_imgs(data, (void *[]){data->wall, data->walk,
		data->collect, data->door}, 4);
	y = 0;
	while (map[y])
	{
		print_textures(map[y], data, &y);
		y++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->p_img, data->plr_x, data->plr_y);
}

int	close_window(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->p_img);
	my_destroy_imgs(data, (void *[]){data->wall, data->walk,
		data->collect, data->door}, 4);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	clear_map_arr(data->map_data.map);
	exit(0);
	return (0);
}

int	close_exit(t_data *data, char *err)
{
	ft_putstr_fd(err, 1);
	mlx_destroy_image(data->mlx_ptr, data->p_img);
	my_destroy_imgs(data, (void *[]){data->wall, data->walk,
		data->collect, data->door}, 4);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	clear_map_arr(data->map_data.map);
	exit(0);
	return (0);
}

int	force_exit(char *err)
{
	ft_putstr_fd(err, 2);
	exit(1);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc != 2)
		force_exit("Error\nInvalide number of arguments\n");
	data_init(&data);
	data.map_data.map = handle_map(argv[1], &data);
	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr)
		data.win_ptr = mlx_new_window(data.mlx_ptr,
				(data.win_x) * 48, data.win_y * 48, "so_long");
	if (!data.mlx_ptr || !data.win_ptr)
	{
		clear_map_arr(data.map_data.map);
		force_exit("Error\nCan't establish connection and create window\n");
	}
	set_exit_position(&data);
	init_plr_frames(&data, 0);
	create_map(data.map_data.map, &data);
	mlx_hook(data.win_ptr, 2, 0, &move_it, &data);
	mlx_hook(data.win_ptr, 17, 0, &close_window, &data);
	mlx_loop(data.mlx_ptr);
}
