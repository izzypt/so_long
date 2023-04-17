NAME=SO_LONG
CFLAGS= -Wall -Wextra
CC=cc
SRC=main.c get_next_line/get_next_line.c validators/map_validators.c graphics/draw.c

MLX_LIB=mlx_linux/libmlx.a

LIBFT_LIB=Libft_SB/libft.a

PRINTF_LIB=printf/printf.a

LDFLAGS= $(PRINTF_LIB) $(LIBFT_LIB) $(MLX_LIB) -lXext -lX11 -lm -lz -g -fsanitize=address

all : $(NAME)

$(NAME) : $(SRC) $(MLX_LIB) $(LIBFT_LIB) $(PRINTF_LIB)
	$(CC) $(SRC) -o $(NAME) $(CFLAGS) $(LDFLAGS)

$(MLX_LIB):
	cd mlx_linux && make
	cd ..

$(LIBFT_LIB):
	cd Libft_SB && make
	cd ..

$(PRINTF_LIB):
	cd ./printf && make
	cd ..

clean:
	rm -f $(NAME)
	cd ./Libft_SB && make clean
	cd ..
	cd ./mlx_linux && make clean
	cd ..
	cd ./printf && make clean
	cd ..

fclean:		clean
		rm -rf $(NAME)

valgrind:	re
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=yes --log-file=valgrind-out.txt ./cub3d maps/line.cub 

re:			fclean all

.PHONY: all clean fclean re