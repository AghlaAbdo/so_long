/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 05:21:52 by aaghla            #+#    #+#             */
/*   Updated: 2024/01/27 09:27:19 by aaghla           ###   ########.fr       */
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
		free(map_line);
		force_exit(map, "Error\nMap is not rectangular\n");
	}
	if (map_line[0] != '1' || map_line[count -1] != '1')
	{
		free(map_line);
		close(data->fd);
		force_exit(map, "Error\nmap is not surrounded by walls\n");
	}
	check_for_characters(map_line, map);
}

void	check_file_format(t_data *data, char *map)
{
	char	*set;

	set = ".ber";
	map = ft_strrchr(map, '.');
	if (!map)
	{
		close(data->fd);
		force_exit(NULL, "Error\nInvalid file format\n");
	}
	while (*set)
	{
		if (*set++ != *map++)
		{
			close(data->fd);
			force_exit(NULL, "Error\nInvalid file format\n");
		}
	}
	if (*set != *map)
	{
		close(data->fd);
		force_exit(NULL, "Error\nInvalid file format\n");
	}
}

void	check_for_characters(char *line, char *map)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] != '1' && line[i] != '0'
			&& line[i] != 'P' && line[i] != 'E' && line[i] != 'C')
		{
			free(line);
			force_exit(map, "Error\nUnkown characters in the map\n");
		}
		i++;
	}
}

void	verify_map_is_valid(t_data *data, char *map)
{
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
}

char	**check_map(t_data *data, char *map)
{
	char	**res;

	verify_map_is_valid(data, map);
	res = ft_split(map, '\n');
	if (!res)
		force_exit(map, "Error\nCan't allocate memory for the program");
	set_plr_position(data, res);
	check_valid_path(data, ft_split(map, '\n'), res, map);
	return (res);
}
