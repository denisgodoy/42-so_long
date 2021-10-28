NAME := so_long

CC := clang

CFLAGS := -Wall -Wextra -Werror -I includes/

SRC := main.c \
		$(addprefix utils/, \
		ft_free_game.c \
		ft_free_map.c \
		ft_close_window.c \
		ft_move_window.c) \
		$(addprefix 42-gnl/, \
		get_next_line.c \
		get_next_line_utils.c) \
		$(addprefix utils/map/, \
		ft_put_walls.c \
		ft_make_map.c \
		ft_read_map.c \
		ft_exit_map.c) \
		$(addprefix utils/validations/, \
		ft_check_args.c \
		ft_map_format.c \
		ft_valid_map.c \
		ft_max_resolution.c \
		ft_validate_map_str.c \
		ft_error_handler.c) \
		$(addprefix utils/sprites/, \
		ft_img_init.c) \
		$(addprefix utils/movements/, \
		ft_key_input.c \
		ft_move_player.c \
		ft_collect_item.c)

BONUS_SRC := main_bonus.c \
			$(addprefix utils_bonus/, \
			ft_free_game_bonus.c \
			ft_free_map_bonus.c \
			ft_close_window_bonus.c \
			ft_move_window_bonus.c) \
			$(addprefix 42-gnl/, \
			get_next_line.c \
			get_next_line_utils.c) \
			$(addprefix utils_bonus/map/, \
			ft_put_walls_bonus.c \
			ft_make_map_bonus.c \
			ft_read_map_bonus.c \
			ft_exit_map_bonus.c) \
			$(addprefix utils_bonus/validations/, \
			ft_check_args_bonus.c \
			ft_map_format_bonus.c \
			ft_valid_map_bonus.c \
			ft_max_resolution_bonus.c \
			ft_validate_map_str_bonus.c \
			ft_error_handler_bonus.c) \
			$(addprefix utils_bonus/sprites/, \
			ft_img_init_bonus.c) \
			$(addprefix utils_bonus/movements/, \
			ft_key_input_bonus.c \
			ft_move_player_bonus.c \
			ft_collect_item_bonus.c \
			ft_move_enemy_bonus.c) \
			$(addprefix utils_bonus/animations/, \
			ft_animate_player_bonus.c \
			ft_animate_enemy_bonus.c \
			ft_animations_bonus.c \
			ft_delay_bonus.c)

OBJ := $(SRC:%.c=%.o)

BONUS_OBJ := $(BONUS_SRC:%.c=%.o)

LIB := -L ./minilibx-linux -lmlx -lXext -lX11 -L ./42-libft -lft

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C ./minilibx-linux
	$(MAKE) -C ./42-libft
	$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $(NAME)

bonus: $(BONUS_OBJ)
	$(MAKE) -C ./minilibx-linux
	$(MAKE) -C ./42-libft
	$(CC) $(CFLAGS) $(BONUS_OBJ) $(LIB) -o $(NAME)

clean:
	$(MAKE) -C ./42-libft clean
	rm -rf $(OBJ)
	rm -rf $(BONUS_OBJ)
	rm -rf $(NAME)

fclean: clean
	$(MAKE) -C ./minilibx-linux clean
	$(MAKE) -C ./42-libft fclean

re: fclean all

commit:
	git add .
	git commit -m "update so_long"
	git push origin main