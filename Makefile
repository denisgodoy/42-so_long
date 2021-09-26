NAME := so_long

CC := clang

FLAGS := -Wall -Wextra -Werror

SRC := main.c

OBJ := $(SRC:%.c=%.o)

LIB := -L ./minilibx -lmlx -lXext -lX11 

all: $(NAME)

$(NAME): clean $(OBJ)
	$(MAKE) -C ./minilibx
	$(CC) $(FLAGS) $(OBJ) $(LIB) -o $(NAME)

clean:
	rm -rf $(OBJ)
	rm -rf $(NAME)

fclean: clean
	$(MAKE) -C minilibx clean

re: fclean all
