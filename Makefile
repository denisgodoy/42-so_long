NAME := so_long

CC := clang

FLAGS := -Wall -Wextra -Werror 

SRC := $(addprefix 42-gnl/, get_next_line.c get_next_line_utils.c) main.c

OBJ := $(SRC:%.c=%.o)

LIB := -L ./minilibx-linux -lmlx -lXext -lX11 -L ./42-libft -lft

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C ./minilibx-linux
	$(MAKE) -C ./42-libft
	$(CC) $(FLAGS) $(OBJ) $(LIB) -o $(NAME)

clean:
	$(MAKE) -C ./42-libft clean
	rm -rf $(OBJ)
	rm -rf $(NAME)

fclean: clean
	$(MAKE) -C ./minilibx-linux clean
	$(MAKE) -C ./42-libft fclean

re: fclean all
