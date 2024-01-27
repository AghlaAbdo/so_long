/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 09:35:57 by aaghla            #+#    #+#             */
/*   Updated: 2024/01/27 09:41:15 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

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
	check_valid_imgs(data, (void *[]){data->wall, data->walk,
		data->collect, data->door_c, data->door_o}, 5);
	init_plr_frames(data);
	init_enm_frames(data);
}

void	data_init(t_data *data)
{
	data->frm = 0;
	data->enm.frm = 0;
	data->enm.interval = 0;
	data->enm.der = -1;
	data->enm.x = 0;
	data->interval = 0;
	data->moves = 0;
	data->der = 0;
	data->map_data.c = 0;
}

void	init_plr_frames(t_data *data)
{
	int	w;
	int	h;

	data->frms_l[0] = mlx_xpm_file_to_image(data->mlx_ptr, P_L_F_1, &w, &h);
	data->frms_l[1] = mlx_xpm_file_to_image(data->mlx_ptr, P_L_F_2, &w, &h);
	data->frms_l[2] = mlx_xpm_file_to_image(data->mlx_ptr, P_L_F_3, &w, &h);
	data->frms_l[3] = mlx_xpm_file_to_image(data->mlx_ptr, P_L_F_4, &w, &h);
	data->frms_l[4] = mlx_xpm_file_to_image(data->mlx_ptr, P_L_F_5, &w, &h);
	data->frms_l[5] = mlx_xpm_file_to_image(data->mlx_ptr, P_L_F_6, &w, &h);
	check_valid_imgs(data, data->frms_l, P_FRAMES);
	data->frms_r[0] = mlx_xpm_file_to_image(data->mlx_ptr, P_R_F_1, &w, &h);
	data->frms_r[1] = mlx_xpm_file_to_image(data->mlx_ptr, P_R_F_2, &w, &h);
	data->frms_r[2] = mlx_xpm_file_to_image(data->mlx_ptr, P_R_F_3, &w, &h);
	data->frms_r[3] = mlx_xpm_file_to_image(data->mlx_ptr, P_R_F_4, &w, &h);
	data->frms_r[4] = mlx_xpm_file_to_image(data->mlx_ptr, P_R_F_5, &w, &h);
	data->frms_r[5] = mlx_xpm_file_to_image(data->mlx_ptr, P_R_F_6, &w, &h);
	check_valid_imgs(data, data->frms_r, P_FRAMES);
}

void	init_enm_frames(t_data *data)
{
	int	w;
	int	h;

	data->enm.frms[0] = mlx_xpm_file_to_image(data->mlx_ptr, ENM_F_1, &w, &h);
	data->enm.frms[1] = mlx_xpm_file_to_image(data->mlx_ptr, ENM_F_2, &w, &h);
	data->enm.frms[2] = mlx_xpm_file_to_image(data->mlx_ptr, ENM_F_3, &w, &h);
	check_valid_imgs(data, data->enm.frms, E_FRAMES);
}
