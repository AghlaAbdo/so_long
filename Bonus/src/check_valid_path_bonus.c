/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_path_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 11:17:41 by aaghla            #+#    #+#             */
/*   Updated: 2024/01/27 09:37:29 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	check_for_invalid(t_data *data, char *map, int e, int p)
{
	if (e != 1)
	{
		if (e == 0)
			force_exit(map, "Error\nNo exit!\n");
		force_exit(map, "Error\nMore than one Exit!\n");
	}
	if (p != 1)
	{
		if (p == 0)
			force_exit(map, "Error\nNo starting position!\n");
		force_exit(map, "Error\nMore than one starting Postion!\n");
	}
	if (data->map_data.c == 0)
		force_exit(map, "Error\nNothing to collect!\n");
}

void	check_path(char **map, char **res)
{
	int	x;
	int	y;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == 'C')
			{
				clear_map_arr(res);
				clear_map_arr(map);
				force_exit(NULL, "Error\nPlayer can't collect every C\n");
			}
			else if (map[y][x] == 'E')
			{
				clear_map_arr(res);
				clear_map_arr(map);
				force_exit(NULL, "Error\nPlayer can't exit the game\n");
			}
		}
	}
	clear_map_arr(map);
}

char	**my_floodfill(t_data *data, char **map, int x, int y)
{
	if (x < 0 || x >= data->win_x || y < 0 || y >= data->win_y
		|| map[y][x] == '1' || map[y][x] == 'v')
		return (map);
	map [y][x] = 'v';
	my_floodfill(data, map, x, y -1);
	my_floodfill(data, map, x +1, y);
	my_floodfill(data, map, x, y +1);
	my_floodfill(data, map, x -1, y);
	return (map);
}

void	check_valid_path(t_data *data, char **map, char **res, char *map_str)
{
	free(map_str);
	if (!map)
	{
		clear_map_arr(res);
		force_exit(NULL, "Error\nCan't allocate memory for the program");
	}
	check_path(my_floodfill(data, map,
			data->plr_x / 48, data->plr_y / 48), res);
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
			force_exit(NULL, "Error\nDon't have access to resources\n");
		}
		i++;
	}
}
