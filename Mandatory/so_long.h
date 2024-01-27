/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:55:53 by aaghla            #+#    #+#             */
/*   Updated: 2024/01/27 10:36:16 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../get_next_line/get_next_line.h"
# include "../Libft/libft.h"
# include <mlx.h>
# include <fcntl.h>
# include <stdio.h>

# define P_R_F_1 "./Mandatory/textures/player1.xpm"
# define P_L_F_1 "./Mandatory/textures/player1_left.xpm"
# define WALL "./Mandatory/textures/wall.xpm"
# define WALK "./Mandatory/textures/walk.xpm"
# define DOOR_CLOSE "./Mandatory/textures/door_close.xpm"
# define DOOR_OPEN "./Mandatory/textures/door_open.xpm"
# define COLLECT "./Mandatory/textures/collect.xpm"

typedef struct s_map
{
	char	**map;
	int		exit_x;
	int		exit_y;
	int		c;
}				t_map;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*p_frm_r;
	void	*p_frm_l;
	void	*wall;
	void	*walk;
	void	*door_o;
	void	*door_c;
	void	*collect;
	int		fd;
	size_t	moves;
	int		win_x;
	int		win_y;
	int		bkp_p_x;
	int		bkp_p_y;
	int		plr_x;
	int		plr_y;
	int		der;
	t_map	map_data;
}			t_data;

char	**handle_map(char *map, t_data *data);
int		move_it(int keysem, t_data *data);
int		force_exit(char *str, char *err);
void	put_wall(t_data *data, int x, int y);
void	put_walk(t_data *data, int x, int y);
void	my_destroy_imgs(t_data *data, void **img, int n);
void	check_for_loss(t_data *data);
void	put_collect(t_data *data, int x, int y);
void	put_door(t_data *data, int x, int y, int multiply);
void	set_plr_position(t_data *data, char **map);
void	data_init(t_data *data);
void	init_imgs(t_data *data);
int		check_wall(t_data *data, int x, int y);
void	check_for_win(t_data *data);
int		close_exit(t_data *data, char *err);
void	clear_map_arr(char **map);
void	check_line(t_data *data, char *map_line, char *map);
void	check_file_format(t_data *data, char *map);
void	check_for_characters(char *line, char *map);
void	check_for_invalid(t_data *data, char *map, int e, int p);
char	**check_map(t_data *data, char *map);
void	check_valid_path(t_data *data, char **map, char **res, char *map_str);
void	check_path(char **map, char **res);
void	check_for_invalid(t_data *data, char *map, int e, int p);
void	check_valid_imgs(t_data *data, void **imgs, int n);
void	my_destroy_imgs(t_data *data, void **img, int n);
size_t	ft_strlen(const char *s);
int		close_window(t_data *data);

#endif