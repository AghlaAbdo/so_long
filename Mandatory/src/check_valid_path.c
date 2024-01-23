/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 11:17:41 by aaghla            #+#    #+#             */
/*   Updated: 2024/01/22 15:58:22 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_for_invalid(t_data *data, char *map, int e, int p)
{
	if (e > 1 || e <= 0 || p > 1 || p <= 0 || data->map_data.c <= 0)
	{
		free(map);
		if (e > 1 || e <= 0)
		{
			if (e == 0)
				force_exit("Error\nNo exit!\n");
			force_exit("Error\nMore than one Exit!\n");
		}
		if (p > 1 || p <= 0)
		{
			if (p == 0)
				force_exit("Error\nNo starting position!\n");
			force_exit("Error\nMore than one starting Postion!\n");
		}
		if (data->map_data.c <= 0)
			force_exit("Error\nNothing to collect!\n");
	}
}

void	check_path(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C')
			{
				clear_map_arr(map);
				force_exit("Error\nPlayer can't collect every C\n");
			}
			else if (map[y][x] == 'E')
			{
				clear_map_arr(map);
				force_exit("Error\nPlayer can't exit the game\n");
			}
			x++;
		}
		y++;
	}
	clear_map_arr(map);
}

char	**check_for_valid_path(t_data *data, char **map, int x, int y)
{
	if (x < 0 || x >= data->win_x || y < 0 || y >= data->win_y
		|| map[y][x] == '1' || map[y][x] == 'v')
		return (map);
	map [y][x] = 'v';
	check_for_valid_path(data, map, x, y -1);
	check_for_valid_path(data, map, x +1, y);
	check_for_valid_path(data, map, x, y +1);
	check_for_valid_path(data, map, x -1, y);
	return (map);
}

void	check_valid_imgs(t_data *data, void **imgs, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (!imgs[i])
		{
			clear_map_arr(data->map_data.map);
			my_destroy_imgs(data, imgs, i);
			force_exit("Error\nDon't have access to resources\n");
		}
		i++;
	}
}
