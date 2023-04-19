NAME=SO_LONG
CFLAGS=-Wall -Wextra
CC=cc
SRC=main.c libs/get_next_line/get_next_line.c validators/map_validators.c validators/item_validators.c graphics/draw.c graphics/draw2.c hooks/hooks.c utils/utils.c utils/ft_itoa.c

MLX_LIB=libs/mlx_linux/libmlx.a

LIBFT_LIB=libs/Libft_SB/libft.a

PRINTF_LIB=libs/printf/printf.a

LDFLAGS= $(PRINTF_LIB) $(LIBFT_LIB) $(MLX_LIB) -lXext -lX11 -lm -lz -g -fsanitize=address 

all : $(NAME)

$(NAME) : $(SRC) $(MLX_LIB) $(LIBFT_LIB) $(PRINTF_LIB) 
	$(CC) $(SRC) -o $(NAME) $(CFLAGS) $(LDFLAGS) 

$(MLX_LIB):
	cd libs/mlx_linux && make
	cd ..

$(LIBFT_LIB):
	cd libs/Libft_SB && make
	cd ..

$(PRINTF_LIB):
	cd libs/printf && make
	cd ..

clean:
	rm -f $(NAME)
	make -C libs/Libft_SB clean
	make -C libs/mlx_linux clean
	make -C libs/printf clean

fclean:		clean
		rm -rf $(NAME)

valgrind:	re
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=yes --log-file=valgrind-out.txt ./cub3d maps/line.cub 

re:			fclean all

.PHONY: all clean fclean re