NAME := so_long

CC := clang

CFLAGS := -Wall -Wextra -Werror

SRC := main.c $(addprefix 42-gnl/, get_next_line.c get_next_line_utils.c) \
$(addprefix utils/map/, walls.c parse.c) $(addprefix utils/validations/, validate_file.c \
validate_map.c) $(addprefix utils/sprites/, init_sprites.c) $(addprefix utils/movements/, key_input.c)

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
