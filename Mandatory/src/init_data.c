/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 09:35:57 by aaghla            #+#    #+#             */
/*   Updated: 2024/01/27 09:28:21 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	set_plr_position(t_data *data, char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				data->plr_x = x * 48;
				data->plr_y = y * 48;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	init_imgs(t_data *data)
{
	int	w;
	int	h;

	data->wall = mlx_xpm_file_to_image(data->mlx_ptr, WALL, &w, &h);
	data->walk = mlx_xpm_file_to_image(data->mlx_ptr, WALK, &w, &h);
	data->collect = mlx_xpm_file_to_image(data->mlx_ptr, COLLECT, &w, &h);
	data->door_c = mlx_xpm_file_to_image(data->mlx_ptr, DOOR_CLOSE, &w, &h);
	data->door_o = mlx_xpm_file_to_image(data->mlx_ptr, DOOR_OPEN, &w, &h);
	data->p_frm_r = mlx_xpm_file_to_image(data->mlx_ptr, P_R_F_1, &w, &h);
	data->p_frm_l = mlx_xpm_file_to_image(data->mlx_ptr, P_L_F_1, &w, &h);
	check_valid_imgs(data, (void *[]){data->wall, data->walk, data->collect,
		data->door_c, data->door_o, data->p_frm_r, data->p_frm_l}, 7);
}

void	data_init(t_data *data)
{
	data->moves = 0;
	data->der = 0;
	data->map_data.c = 0;
}

void	my_destroy_imgs(t_data *data, void **img, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		mlx_destroy_image(data->mlx_ptr, img[i++]);
	}
}
