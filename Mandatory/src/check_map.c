/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 05:21:52 by aaghla            #+#    #+#             */
/*   Updated: 2024/01/22 15:58:19 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_line(t_data *data, char *map_line, char *map)
{
	int	count;

	count = ft_strlen(map_line);
	if (count != data->win_x)
	{
		close(data->fd);
		free(map);
		free(map_line);
		force_exit("Error\nMap is not rectangular\n");
	}
	if (map_line[0] != '1' || map_line[count -1] != '1')
	{
		free(map_line);
		free(map);
		close(data->fd);
		force_exit("Error\nmap is not surrounded by walls\n");
	}
	check_for_character(map_line);
}

void	check_file_path(t_data *data, char *map)
{
	char	*set;
	int		i;

	set = ".ber";
	i = ft_strlen(map) - 4;
	while (map[i])
	{
		if (map[i++] != *set++)
		{
			close(data->fd);
			force_exit("Error\nInvalid file format\n");
		}
	}
}

void	check_for_character(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] != '1' && line[i] != '0'
			&& line[i] != 'P' && line[i] != 'E' && line[i] != 'C')
			force_exit("Error\nUnkown characters in the map\n");
		i++;
	}
}

char	**check_map(t_data *data, char *map)
{
	char	**res;
	int		i;
	int		e;
	int		p;

	i = 0;
	e = 0;
	p = 0;
	while (map[i])
	{
		if (map[i] == 'E')
			e += 1;
		else if (map[i] == 'P')
			p += 1;
		else if (map[i] == 'C')
			data->map_data.c += 1;
		i++;
	}
	check_for_invalid(data, map, e, p);
	res = ft_split(map, '\n');
	set_plr_position(data, res);
	check_path(check_for_valid_path(data,
			ft_split(map, '\n'), data->plr_x / 48, data->plr_y / 48));
	free(map);
	return (res);
}
