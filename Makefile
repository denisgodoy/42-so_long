NAME := so_long

CC := clang

CFLAGS := -Wall -Wextra -Werror

SRC := main.c $(addprefix 42-gnl/, get_next_line.c get_next_line_utils.c) \
$(addprefix utils/map/, ft_put_walls.c ft_make_map.c ft_read_map.c) \
$(addprefix utils/validations/, ft_check_args.c ft_map_format.c ft_valid_map.c ft_max_resolution.c \
ft_validate_map_str.c ft_error_handler.c) $(addprefix utils/sprites/, ft_img_init.c) \
$(addprefix utils/movements/, ft_key_input.c ft_move_player.c)

OBJ := $(SRC:%.c=%.o)

LIB := -L ./minilibx-linux -lmlx -lXext -lX11 -L ./42-libft -lft

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C ./minilibx-linux
	$(MAKE) -C ./42-libft
	$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $(NAME)

clean:
	$(MAKE) -C ./42-libft clean
	rm -rf $(OBJ)
	rm -rf $(NAME)

fclean: clean
	$(MAKE) -C ./minilibx-linux clean
	$(MAKE) -C ./42-libft fclean

re: fclean all
