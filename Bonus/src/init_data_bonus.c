/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 09:35:57 by aaghla            #+#    #+#             */
/*   Updated: 2024/01/24 14:43:42 by aaghla           ###   ########.fr       */
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

void	set_exit_position(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map_data.map[y])
	{
		x = 0;
		while (data->map_data.map[y][x])
		{
			if (data->map_data.map[y][x] == 'E')
			{
				data->map_data.exit_x = x * 48;
				data->map_data.exit_y = y * 48;
				return ;
			}
			x++;
		}
		y++;
	}
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

void	init_plr_frames(t_data *data, int der)
{
	int	w;
	int	h;

	if (der == 1)
	{
		data->frms[0] = mlx_xpm_file_to_image(data->mlx_ptr, P_L_F_1, &w, &h);
		data->frms[1] = mlx_xpm_file_to_image(data->mlx_ptr, P_L_F_2, &w, &h);
		data->frms[2] = mlx_xpm_file_to_image(data->mlx_ptr, P_L_F_3, &w, &h);
		data->frms[3] = mlx_xpm_file_to_image(data->mlx_ptr, P_L_F_4, &w, &h);
		data->frms[4] = mlx_xpm_file_to_image(data->mlx_ptr, P_L_F_5, &w, &h);
		data->frms[5] = mlx_xpm_file_to_image(data->mlx_ptr, P_L_F_6, &w, &h);
	}
	else if (der == 0)
	{
		data->frms[0] = mlx_xpm_file_to_image(data->mlx_ptr, P_R_F_1, &w, &h);
		data->frms[1] = mlx_xpm_file_to_image(data->mlx_ptr, P_R_F_2, &w, &h);
		data->frms[2] = mlx_xpm_file_to_image(data->mlx_ptr, P_R_F_3, &w, &h);
		data->frms[3] = mlx_xpm_file_to_image(data->mlx_ptr, P_R_F_4, &w, &h);
		data->frms[4] = mlx_xpm_file_to_image(data->mlx_ptr, P_R_F_5, &w, &h);
		data->frms[5] = mlx_xpm_file_to_image(data->mlx_ptr, P_R_F_6, &w, &h);
	}
	check_valid_imgs(data, data->frms, P_FRAMES);
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
