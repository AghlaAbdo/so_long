/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 13:27:00 by aaghla            #+#    #+#             */
/*   Updated: 2024/01/24 14:43:12 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	clear_enm_pos(t_data *data)
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
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->enm.frms[data->enm.frm],
		data->enm.x, data->enm.y);
}

int	render_frame(t_data *data)
{
	if (data->enm.x != 0)
		move_enemy(data);
	if (data->interval == 1000)
	{
		data->frm = (data->frm +1) % 6;
		data->enm.frm = (data->enm.frm +1) % 3;
		if (data->map_data.map[data->plr_y / 48][data->plr_x / 48] == '0'
			|| data->map_data.map[data->plr_y / 48][data->plr_x / 48] == 'P'
			|| data->map_data.map[data->plr_y / 48][data->plr_x / 48] == 'C')
			put_walk(data, data->plr_x, data->plr_y);
		else if (data->map_data.map[data->plr_y / 48][data->plr_x / 48] == 'E')
			put_door(data, data->plr_x, data->plr_y, 0);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->frms[data->frm], data->plr_x, data->plr_y);
		if (data->enm.x != 0)
			clear_enm_pos(data);
		data->interval = 0;
	}
	data->interval += 1;
	return (0);
}

void	print_move(t_data *data)
{
	char	*s;
	char	*n_move;

	n_move = ft_itoa(data->moves);
	s = ft_strjoin(ft_strdup("Move: "), n_move);
	put_wall(data, 0, 0);
	put_wall(data, 48, 0);
	put_wall(data, 96, 0);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 24, 24, 0xFFFFFF, s);
	free(n_move);
	free(s);
}

void	handle_key_input(int keysem, t_data *data)
{
	if ((keysem == 0 && !check_wall(data, data->plr_x -48, data->plr_y))
		|| (keysem == 1 && !check_wall(data, data->plr_x, data->plr_y + 48))
		|| (keysem == 2 && !check_wall(data, data->plr_x + 48, data->plr_y))
		|| (keysem == 13 && !check_wall(data, data->plr_x, data->plr_y - 48)))
	{
		put_walk(data, data->plr_x, data->plr_y);
		if (keysem == 0)
			data->plr_x -= 48;
		else if (keysem == 1)
			data->plr_y += 48;
		else if (keysem == 2)
			data->plr_x += 48;
		else if (keysem == 13)
			data->plr_y -= 48;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->frms[0],
			data->plr_x, data->plr_y);
		if (data->map_data.map[data->bkp_p_y / 48][data->bkp_p_x / 48] == 'E')
			put_door(data, data->bkp_p_x, data->bkp_p_y, 0);
		data->moves += 1;
		print_move(data);
	}
}

int	move_it(int keysem, t_data *data)
{
	if (keysem == 0 || keysem == 1 || keysem == 2 || keysem == 13)
	{
		data->bkp_p_x = data->plr_x;
		data->bkp_p_y = data->plr_y;
		change_der(data, keysem);
		handle_key_input(keysem, data);
		if (data->map_data.map[data->plr_y / 48][data->plr_x / 48] == 'C')
		{
			data->map_data.c -= 1;
			data->map_data.map[data->plr_y / 48][data->plr_x / 48] = '0';
		}
		check_for_win(data);
		check_for_loss(data);
	}
	else if (keysem == 53)
		close_window(data);
	return (0);
}
