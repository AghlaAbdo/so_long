/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 13:28:12 by aaghla            #+#    #+#             */
/*   Updated: 2024/01/22 20:13:56 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_wall_line(t_data *data, char *map_line, char *map)
{
	int	i;
	int	count;

	count = ft_strlen(map_line);
	i = 0;
	if (count != data->win_x || map[0] == '\n')
	{
		free(map_line);
		free(map);
		close(data->fd);
		force_exit("Error\nMap is not rectangular\n");
	}
	while (map_line[i] && map_line[i] != '\n')
	{
		if (map_line[i] != '1')
		{
			free(map_line);
			free(map);
			close(data->fd);
			force_exit("Error\nMap is not surrounded by walls\n");
		}
		i++;
	}
}

int	map_height(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	map_width(char *map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

char	**handle_the_rest(t_data *data, char *map_line, char *map, char *temp)
{
	int	count;

	while (map_line)
	{
		free(map_line);
		map_line = get_next_line(data->fd);
		if (!map_line && temp[count] == '\n')
			force_exit("Error\nMap is not rectangular\n");
		free(temp);
		if (!map_line)
			break ;
		data->win_y += 1;
		count = ft_strlen(map_line);
		if (map_line[count] != '\n')
		{
			check_wall_line(data, map_line, map);
			map = ft_strjoin(map, map_line);
			return (close(data->fd), free(map_line), check_map(data, map));
		}
		check_line(data, map_line, map);
		temp = ft_strdup(map_line);
		map = ft_strjoin(map, map_line);
	}
	return (close(data->fd), check_map(data, map));
}

char	**handle_map(char *map, t_data *data)
{
	char	*map_line;
	int		count;

	data->fd = open(map, O_RDONLY);
	if (data->fd < 0)
		force_exit("Error\nInvalid file path\n");
	check_file_path(data, map);
	map_line = get_next_line(data->fd);
	if (!map_line)
		force_exit("Error\nFile is empty\n");
	count = ft_strlen(map_line);
	data->win_x = count;
	map = ft_strjoin(ft_strdup(""), map_line);
	check_wall_line(data, map_line, map);
	data->win_y = 1;
	return (handle_the_rest(data, map_line, map, ft_strdup("")));
}
