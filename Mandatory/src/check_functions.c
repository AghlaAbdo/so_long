/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 09:50:34 by aaghla            #+#    #+#             */
/*   Updated: 2024/01/26 10:29:19 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_wall(t_data *data, int x, int y)
{
	if (data->map_data.map[y / 48][x / 48] == '1')
		return (1);
	return (0);
}

void	clear_map_arr(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	check_for_win(t_data *data)
{
	static int	is_open;

	if (!data->map_data.c && !is_open)
	{
		put_door(data, data->map_data.exit_x, data->map_data.exit_y, 1);
		is_open = 1;
	}
	if (!data->map_data.c && data->plr_x == data->map_data.exit_x
		&& data->plr_y == data->map_data.exit_y)
	{
		close_exit(data, "Congratulations! You Won :D\n");
	}
}
