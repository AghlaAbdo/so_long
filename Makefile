NAME 		= so_long
NAME_BONS 	= so_long_bonus
CC 			= cc
CFLAGS		= -Wall -Wextra -Werror
LIBFT		=  ./Libft/libft.a
HEADER		= ./Mandatory/so_long.h
HEADER_BONS = ./Bonus/so_long_bonus.h
HEADER_GNL	= ./get_next_line/get_next_line.h

SRCS		= ./Mandatory/src/handle_map.c			\
			 ./Mandatory/src/check_map.c			\
			 ./Mandatory/src/animation.c			\
			 ./Mandatory/src/print_sprites.c		\
			 ./Mandatory/src/init_data.c			\
			 ./Mandatory/src/check_valid_path.c		\
			 ./Mandatory/src/check_functions.c		\
			 ./Mandatory/so_long.c
			
SRCS_BONS 	= ./Bonus/src/handle_map_bonus.c		\
			 ./Bonus/src/check_map_bonus.c			\
			 ./Bonus/src/animation_bonus.c			\
			 ./Bonus/src/enemy_bonus.c				\
			 ./Bonus/src/print_sprites_bonus.c		\
			 ./Bonus/src/init_data_bonus.c			\
			 ./Bonus/src/check_valid_path_bonus.c	\
			 ./Bonus/src/check_functions_bonus.c	\
			 ./Bonus/so_long_bonus.c

SRCS_GNL		= ./get_next_line/get_next_line.c	\
			 ./get_next_line/get_next_line_utils.c
				
OBJS = $(SRCS:.c=.o)
OBJS_BONS = $(SRCS_BONS:.c=.o)
OBJS_GNL = $(SRCS_GNL:.c=.o)

all: libft $(NAME)

bonus: libft $(NAME_BONS)

$(NAME) : $(OBJS) $(OBJS_GNL) $(LIBFT) 
	@echo "Building the game.."
	@$(CC) $(CFLAGS) $(LIBFT) -lmlx -framework OpenGL -framework AppKit $(OBJS) $(OBJS_GNL) -o $@

$(NAME_BONS): $(OBJS_BONS) $(OBJS_GNL) $(LIBFT)
	@echo "Building the game.."
	@$(CC) $(CFLAGS) $(LIBFT) -lmlx -framework OpenGL -framework AppKit  $(OBJS_BONS) $(OBJS_GNL) -o $(NAME_BONS)

libft:
	@make -C Libft

get_next_line/%.o: get_next_line/%.c $(HEADER_GNL)
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) -c $< -o $@

%_bonus.o: %_bonus.c $(HEADER_BONS) $(OBJS_GNL)
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) -c $< -o $@

%.o:%.c $(HEADER) $(OBJS_GNL)
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Removed object files"
	@rm -f $(OBJS)
	@rm -f $(OBJS_BONS)
	@rm -f $(OBJS_GNL)
	@make -C Libft clean

fclean: clean
	@echo "Removed executable"
	@rm -f $(NAME)
	@rm -f $(NAME_BONS)
	@rm -f $(LIBFT)

re: fclean all

.PHONY: all bonus libft clean fclean re