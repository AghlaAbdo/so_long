/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:54:48 by aaghla            #+#    #+#             */
/*   Updated: 2024/01/27 10:41:21 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	create_map(char **map, t_data *data)
{
	int	y;

	y = 0;
	while (map[y])
	{
		print_textures(map[y], data, &y);
		y++;
	}
	mlx_string_put(data->mlx_ptr, data->win_ptr, 5, 10, 0xFFFFFF, "Move: 0");
	set_enemy_pos(data, map);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->frms_r[0], data->plr_x, data->plr_y);
	if (data->enm.x != 0)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->enm.frms[0], data->enm.x, data->enm.y);
}

int	close_window(t_data *data)
{
	my_destroy_imgs(data, data->enm.frms, E_FRAMES);
	my_destroy_imgs(data, data->frms_r, P_FRAMES);
	my_destroy_imgs(data, data->frms_l, P_FRAMES);
	my_destroy_imgs(data, (void *[]){data->wall, data->walk,
		data->collect, data->door_c, data->door_o}, 5);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	clear_map_arr(data->map_data.map);
	exit(0);
	return (0);
}

int	close_exit(t_data *data, char *err)
{
	ft_putstr_fd(err, 1);
	my_destroy_imgs(data, data->enm.frms, E_FRAMES);
	my_destroy_imgs(data, data->frms_r, P_FRAMES);
	my_destroy_imgs(data, data->frms_l, P_FRAMES);
	my_destroy_imgs(data, (void *[]){data->wall, data->walk,
		data->collect, data->door_c, data->door_o}, 5);
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
		force_exit(NULL, "Error\nCan't create window\n");
	}
	init_imgs(&data);
	create_map(data.map_data.map, &data);
	mlx_loop_hook(data.mlx_ptr, &render_frame, &data);
	mlx_hook(data.win_ptr, 2, 0, &move_it, &data);
	mlx_hook(data.win_ptr, 17, 0, &close_window, &data);
	mlx_loop(data.mlx_ptr);
}
