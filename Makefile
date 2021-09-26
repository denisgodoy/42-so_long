NAME := so_long

CC := clang

FLAGS := -Wall -Wextra -Werror

SRC := main.c

LIB := -L ./mlx -lmlx -lXext -lX11

all: $(NAME)

mlx:
	git clone https://github.com/42Paris/minilibx-linux.git mlx
	$(MAKE) -C ./mlx

$(NAME): clean
	$(CC) -o $(NAME) $(SRC) $(LIB)

clean:
	rm -rf $(NAME)

fclean: clean
	rm -rf mlx

re: fclean mlx all
