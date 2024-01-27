/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:55:53 by aaghla            #+#    #+#             */
/*   Updated: 2024/01/27 11:17:53 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../get_next_line/get_next_line.h"
# include "../Libft/libft.h"
# include <mlx.h>
# include <fcntl.h>

# define P_FRAMES 6
# define E_FRAMES 3
# define P_R_F_1 "./Bonus/textures/player1.xpm"
# define P_R_F_2 "./Bonus/textures/player2.xpm"
# define P_R_F_3 "./Bonus/textures/player3.xpm"
# define P_R_F_4 "./Bonus/textures/player4.xpm"
# define P_R_F_5 "./Bonus/textures/player5.xpm"
# define P_R_F_6 "./Bonus/textures/player6.xpm"
# define P_L_F_1 "./Bonus/textures/player1_left.xpm"
# define P_L_F_2 "./Bonus/textures/player2_left.xpm"
# define P_L_F_3 "./Bonus/textures/player3_left.xpm"
# define P_L_F_4 "./Bonus/textures/player4_left.xpm"
# define P_L_F_5 "./Bonus/textures/player5_left.xpm"
# define P_L_F_6 "./Bonus/textures/player6_left.xpm"
# define WALL "./Bonus/textures/wall.xpm"
# define WALK "./Bonus/textures/walk.xpm"
# define DOOR_CLOSE "./Bonus/textures/door_close.xpm"
# define DOOR_OPEN "./Bonus/textures/door_open.xpm"
# define COLLECT "./Bonus/textures/collect.xpm"
# define ENM_F_1 "./Bonus/textures/enm_1.xpm"
# define ENM_F_2 "./Bonus/textures/enm_2.xpm"
# define ENM_F_3 "./Bonus/textures/enm_3.xpm"

typedef struct s_enm
{
	void	*frms[3];
	int		x;
	int		y;
	int		frm;
	int		interval;
	int		der;
}				t_enm;

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
	void	*frms_r[6];
	void	*frms_l[6];
	void	*wall;
	void	*walk;
	void	*collect;
	void	*door_c;
	void	*door_o;
	int		fd;
	size_t	moves;
	int		frm;
	int		win_x;
	int		win_y;
	int		bkp_p_x;
	int		bkp_p_y;
	int		plr_x;
	int		plr_y;
	int		interval;
	int		der;
	t_map	map_data;
	t_enm	enm;
}			t_data;

char	**handle_map(char *map, t_data *data);
int		move_it(int keysem, t_data *data);
int		render_frame(t_data *data);
int		force_exit(char *str, char *err);
void	create_map(char **map, t_data *data);
void	put_wall(t_data *data, int x, int y);
void	put_walk(t_data *data, int x, int y);
void	set_enemy_pos(t_data *data, char **map);
void	my_destroy_imgs(t_data *data, void **img, int n);
void	init_plr_frames(t_data *data);
void	print_textures(char *map, t_data *data, int *y);
void	print_move(t_data *data);
void	put_collect(t_data *data, int x, int y);
void	put_door(t_data *data, int x, int y, int multiply);
void	set_plr_position(t_data *data, char **map);
void	data_init(t_data *data);
void	init_imgs(t_data *data);
void	init_enm_frames(t_data *data);
void	move_enemy(t_data *data);
int		check_wall(t_data *data, int x, int y);
void	check_for_win(t_data *data);
void	check_for_loss(t_data *data);
int		close_exit(t_data *data, char *err);
void	clear_map_arr(char **map);
void	check_line(t_data *data, char *map_line, char *map);
void	check_file_format(t_data *data, char *map);
void	check_for_characters(t_data *data, char *line, char *map);
void	check_for_invalid(t_data *data, char *map, int e, int p);
char	**check_map(t_data *data, char *map);
void	check_valid_path(t_data *data, char **map, char **res, char *map_str);
void	check_path(char **map, char **res);
void	check_valid_imgs(t_data *data, void **imgs, int n);
void	my_destroy_imgs(t_data *data, void **img, int n);
int		close_window(t_data *data);

#endif