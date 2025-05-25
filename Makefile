NAME = so_long

SRC = cheaks.c flod_cheak.c get_next_line.c get_next_line_utils.c main.c read_and_path.c \
	  so_long_utils_one.c so_long_utils_three.c so_long_utils_two.c utils_one.c utils_two.c

OBJS = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

MLX_DIR = /usr/include/minilibx-linux/
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11

all: $(NAME)

$(NAME): $(OBJS) so_long.h
	$(CC) $(OBJS) $(MLX_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY : clean re fclean all
