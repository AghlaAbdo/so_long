/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 22:15:42 by aaghla            #+#    #+#             */
/*   Updated: 2024/01/22 20:12:15 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	set_enemy_pos(t_data *data, char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] != '1' && map[y][x] != 'P'
				&& map[y][x +1] != '1' && map[y][x +1] != 'P'
				&& map[y][x -1] != '1' && map[y][x -1] != 'P'
				&& ((map[y +1][x] != '1' && map[y +1][x] != 'P')
				|| (map[y -1][x] != '1' && map[y +1][x] != 'P')))
			{
				data->enm.x = x * 48;
				data->enm.y = y * 48;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	move_right(t_data *data)
{
	if (data->map_data.map[data->enm.y / 48]
		[data->enm.x / 48] == 'C')
		put_collect(data, data->enm.x, data->enm.y);
	else if (data->map_data.map[data->enm.y / 48]
		[data->enm.x / 48] == 'E')
	{
		if (data->map_data.c == 0)
			put_door(data, data->enm.x, data->enm.y, 1);
		else
			put_door(data, data->enm.x, data->enm.y, 0);
	}
	else
		put_walk(data, data->enm.x, data->enm.y);
	data->enm.x += 48;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->enm.frms[data->enm.frm], data->enm.x, data->enm.y);
	if (data->map_data.map[data->enm.y / 48]
		[data->enm.x / 48 +1] == '1')
		data->enm.der *= -1;
}

void	move_left(t_data *data)
{
	if (data->map_data.map[data->enm.y / 48]
		[data->enm.x / 48] == 'C')
		put_collect(data, data->enm.x, data->enm.y);
	else if (data->map_data.map[data->enm.y / 48]
		[data->enm.x / 48] == 'E')
	{
		if (data->map_data.c == 0)
			put_door(data, data->enm.x, data->enm.y, 1);
		else
			put_door(data, data->enm.x, data->enm.y, 0);
	}
	else
		put_walk(data, data->enm.x, data->enm.y);
	data->enm.x -= 48;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->enm.frms[data->enm.frm], data->enm.x, data->enm.y);
	if (data->map_data.map[data->enm.y / 48]
		[data->enm.x / 48 -1] == '1')
		data->enm.der *= -1;
}

void	move_enemy(t_data *data)
{
	if (data->enm.interval == 5000)
	{
		if (data->enm.der == -1 && data->map_data.map[data->enm.y / 48]
			[data->enm.x / 48 +1] != '1')
			move_right(data);
		else if (data->enm.der == 1 && data->map_data.map[data->enm.y / 48]
			[data->enm.x / 48 -1] != '1')
			move_left(data);
		data->enm.interval = 0;
		check_for_loss(data);
	}
	data->enm.interval += 1;
}
