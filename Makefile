NAME=SO_LONG
CFLAGS= -Wall -Wextra
CC=cc
SRC=main.c get_next_line/get_next_line.c

MLX_LIB=mlx_linux/libmlx.a

LIBFT_LIB=Libft_SB/libft.a

PRINTF_LIB=printf/printf.a

LDFLAGS= $(PRINTF_LIB) $(LIBFT_LIB) $(MLX_LIB) -lXext -lX11 -lm -lz

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