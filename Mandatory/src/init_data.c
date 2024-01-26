/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 09:35:57 by aaghla            #+#    #+#             */
/*   Updated: 2024/01/26 10:11:25 by aaghla           ###   ########.fr       */
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

// void	set_exit_position(t_data *data)
// {
// 	int	x;
// 	int	y;

// 	y = 0;
// 	while (data->map_data.map[y])
// 	{
// 		x = 0;
// 		while (data->map_data.map[y][x])
// 		{
// 			if (data->map_data.map[y][x] == 'E')
// 			{
// 				data->map_data.exit_x = x * 48;
// 				data->map_data.exit_y = y * 48;
// 				return ;
// 			}
// 			x++;
// 		}
// 		y++;
// 	}
// }

void	data_init(t_data *data)
{
	// data->interval = 0;
	data->moves = 0;
	data->der = 0;
	data->map_data.c = 0;
}

// void	init_plr_frames(t_data *data, int der)
// {
// 	int	w;
// 	int	h;

// 	if (der == 1)
// 	{
// 		data->p_frm_r = mlx_xpm_file_to_image(data->mlx_ptr, P_L_F_1, &w, &h);
// 	}
// 	else if (der == 0)
// 	{
// 		data->p_frm_r = mlx_xpm_file_to_image(data->mlx_ptr, P_R_F_1, &w, &h);
// 	}
// 	if (!data->p_frm_r)
// 	{
// 		clear_map_arr(data->map_data.map);
// 		force_exit("Error\nDon't have access to resources\n");
// 	}
// }
