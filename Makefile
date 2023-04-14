CC=gcc
CFLAGS=-Wall -Wextra
LDFLAGS=-L mlx_linux/ -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz
LIBFT = Libft_SB
SRC=so_long.c
OBJ=$(SRC:.c=.o) get_next_line.o Libft_SB/libft.a
EXEC=so_long

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LDFLAGS) -o $(EXEC)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

get_next_line.o: get_next_line.c
	$(CC) $(CFLAGS) -c $< -o $@

Libft_SB/libft.a:
	cd ./Libft_SB && make

clean:
	rm -f $(OBJ) $(EXEC)
	cd ./Libft_SB && make clean