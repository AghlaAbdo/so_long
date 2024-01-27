/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 13:27:00 by aaghla            #+#    #+#             */
/*   Updated: 2024/01/27 09:20:09 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	print_move(t_data *data)
{
	char	*s;
	char	*n_move;

	n_move = ft_itoa(data->moves);
	if (!n_move)
		force_exit(NULL, "Error\nCan't allocate memory for the program");
	s = ft_strjoin(ft_strdup("Move: "), n_move);
	if (!s)
		force_exit(n_move, "Error\nCan't allocate memory for the program");
	ft_putstr_fd(s, 1);
	ft_putchar_fd('\n', 1);
	free(n_move);
	free(s);
}

void	update_frames(t_data *data)
{
	if (data->map_data.map[data->plr_y / 48][data->plr_x / 48] == 'C')
		put_walk(data, data->plr_x, data->plr_y);
	if (data->der == 0)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->p_frm_r,
			data->plr_x, data->plr_y);
	else if (data->der == 1)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->p_frm_l,
			data->plr_x, data->plr_y);
	if (data->map_data.map[data->bkp_p_y / 48][data->bkp_p_x / 48] == 'E')
		put_door(data, data->bkp_p_x, data->bkp_p_y, 0);
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
		update_frames(data);
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
		if (data->der == 0 && keysem == 0)
			data->der = 1;
		else if (data->der == 1 && keysem == 2)
			data->der = 0;
		handle_key_input(keysem, data);
		if (data->map_data.map[data->plr_y / 48][data->plr_x / 48] == 'C')
		{
			data->map_data.c -= 1;
			data->map_data.map[data->plr_y / 48][data->plr_x / 48] = '0';
		}
		check_for_win(data);
	}
	else if (keysem == 53)
		close_window(data);
	return (0);
}
