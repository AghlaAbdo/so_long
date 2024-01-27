/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 13:28:12 by aaghla            #+#    #+#             */
/*   Updated: 2024/01/27 10:52:13 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_wall_line(t_data *data, char *map_line, char *map)
{
	int	i;
	int	count;

	count = ft_strlen(map_line);
	i = 0;
	if (count != data->win_x || map_line[0] == '\n')
	{
		free(map_line);
		close(data->fd);
		force_exit(map, "Error\nMap is not rectangular\n");
	}
	while (map_line[i] && map_line[i] != '\n')
	{
		if (map_line[i] != '1')
		{
			free(map_line);
			close(data->fd);
			force_exit(map, "Error\nMap is not surrounded by walls\n");
		}
		i++;
	}
}

void	free_and_exit(char *map_line, char *map, char *temp)
{
	free(temp);
	free(map_line);
	force_exit(map, "Error\nCan't allocate memory for the program");
}

char	**handle_last_line(t_data *data, char *map_line, char *map)
{
	check_wall_line(data, map_line, map);
	map = ft_strjoin(map, map_line);
	close(data->fd);
	free(map_line);
	if (!map)
		force_exit(NULL, "Error\nCan't allocate memory for the program");
	return (check_map(data, map));
}

char	**handle_the_rest(t_data *data, char *map_line, char *map, char *temp)
{
	int	count;

	if (!temp)
		free_and_exit(map_line, map, temp);
	count = 0;
	while (map_line)
	{
		free(map_line);
		map_line = get_next_line(data->fd);
		if (!map_line && temp[count] == '\n')
			force_exit(temp, "Error\nMap is not rectangular\n");
		free(temp);
		if (!map_line)
			break ;
		data->win_y += 1;
		count = ft_strlen(map_line);
		if (map_line[count] != '\n')
			return (handle_last_line(data, map_line, map));
		check_line(data, map_line, map);
		temp = ft_strdup(map_line);
		map = ft_strjoin(map, map_line);
		if (!temp || !map)
			free_and_exit(map_line, map, temp);
	}
	return (close(data->fd), check_map(data, map));
}

char	**handle_map(char *map, t_data *data)
{
	char	*map_line;
	int		count;

	data->fd = open(map, O_RDONLY);
	if (data->fd < 0)
		force_exit(NULL, "Error\nInvalid file path\n");
	check_file_format(data, map);
	map_line = get_next_line(data->fd);
	if (!map_line)
	{
		close(data->fd);
		force_exit(NULL, "Error\nFile is empty\n");
	}
	count = ft_strlen(map_line);
	data->win_x = count;
	map = ft_strjoin(ft_strdup(""), map_line);
	if (!map)
	{
		close(data->fd);
		force_exit(map_line, "Error\nCan't allocate memory for the program");
	}
	check_wall_line(data, map_line, map);
	data->win_y = 1;
	return (handle_the_rest(data, map_line, map, ft_strdup("")));
}
