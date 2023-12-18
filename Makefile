NAME  = so_long

CC    = gcc

FLAGS = -Wall -Wextra -Werror

PRINTF = ./printf/libftprintf.a

SRCS  =      map_cont.c getnextline/get_next_line_utils.c getnextline/get_next_line.c \
        	 printf/ft_printf.c printf/ft_printfutils.c so_long_utils2.c \
             so_long_utils.c mlx.c so_long.c collect_coin.c \
                          
OBJS  = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		make -C ./printf
		make -C ./mlx
		$(CC) $(FLAGS) $(OBJS) $(PRINTF) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
		make clean -C ./printf
		make clean -C ./mlx
		rm -rf $(OBJS)

fclean: clean
		rm -rf $(NAME) $(PRINTF)

re:	fclean all

.PHONY: all clean fclean re


