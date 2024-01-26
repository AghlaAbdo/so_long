/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:55:53 by aaghla            #+#    #+#             */
/*   Updated: 2024/01/26 08:56:48 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../get_next_line/get_next_line.h"
# include "../Libft/libft.h"
# include <mlx.h>
# include <fcntl.h>

# define P_FRAMES 2
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
	int		moves;
	int		win_x;
	int		win_y;
	int		bkp_p_x;
	int		bkp_p_y;
	int		plr_x;
	int		plr_y;
	int		interval;
	int		der;
	t_map	map_data;
}			t_data;

char	**handle_map(char *map, t_data *data);
int		move_it(int keysem, t_data *data);
int		force_exit(char *err);
void	create_map(char **map, t_data *data);
void	put_wall(t_data *data, int x, int y);
void	data_imgs_des_init(t_data *data, int der);
void	put_walk(t_data *data, int x, int y);
void	my_destroy_imgs(t_data *data, void **img, int n);
void	init_plr_frames(t_data *data, int der);
void	check_for_loss(t_data *data);
void	print_textures(char *map, t_data *data, int *y);
void	print_move(t_data *data);
void	print_move(t_data *data);
void	put_collect(t_data *data, int x, int y);
void	put_door(t_data *data, int x, int y, int multiply);
void	set_plr_position(t_data *data, char **map);
void	set_exit_position(t_data *data);
void	data_init(t_data *data);
int		check_wall(t_data *data, int x, int y);
void	check_for_win(t_data *data);
void	change_der(t_data *data, int keysem);
void	data_imgs_des_init(t_data *data, int der);
int		close_exit(t_data *data, char *err);
void	clear_map_arr(char **map);
void	check_line(t_data *data, char *map_line, char *map);
void	check_file_path(t_data *data, char *map);
void	check_for_character(char *line);
void	check_for_invalid(t_data *data, char *map, int e, int p);
char	**check_map(t_data *data, char *map);
char	**check_for_valid_path(t_data *data, char **map, int x, int y);
void	check_path(char **map);
void	check_for_invalid(t_data *data, char *map, int e, int p);
void	check_valid_imgs(t_data *data, void **imgs, int n);
void	my_destroy_imgs(t_data *data, void **img, int n);
size_t	ft_strlen(const char *s);
int		close_window(t_data *data);

#endif