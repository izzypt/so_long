#include "mlx_linux/mlx.h"
#include "Libft_SB/libft.h"
#include "get_next_line.h"
#include <unistd.h>

typedef struct	s_vars {
    void	*mlx_ptr;
    void	*win_ptr;
}				t_vars;

typedef struct map_vars {
	int	player_num;
	int collectile_num;
	int	num_of_lines;
	int	lines_read;
} map_vars;

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	deal_key(int keycode, void *param)
{
	t_vars	*vars;

	vars = (t_vars *)param;
	static int x;
	static int y;

	x = 250;
	y = 250;
	x += 1;
	ft_putchar('X');
	mlx_pixel_put(vars->mlx_ptr, vars->win_ptr, x + 1, y, 0xFFFFFF);
	return (0);
}

int	validate_map(char *line)
{
	map_vars *vars;
	int	i;
	static int	lines;

	i = 0;
    vars = malloc(sizeof(map_vars));
    if (vars == NULL) 
	{
        return 0;
    }
	vars->player_num = 5;
	vars->collectile_num = 10;
	vars->num_of_lines = 30;

	while (line[i] != '\0')
	{
		break;
	}

	printf("%d %d %d", vars->player_num, vars->collectile_num, vars->num_of_lines);
	return (1);
}

int	read_map(char *map)
{
	int 	fd;
	char	*line;
	char	**matrix;
	int		i;
	int		j;

	i = 0;
	fd = open(map, O_RDONLY);
	matrix = (char **) malloc(MAX_LINES * sizeof(char *));
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
		{
			printf("Finished reading the %s\n", map);
			printf("Num of lines is %d\n", i);
			break;
		}
		matrix[i] = (char *) malloc((ft_strlen(line) + 1) * sizeof(char));
		ft_strcpy(matrix[i], line);
		//validate_map(line);
		i++;
	}
}

int	main(int argc, char **argv)
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_vars	vars;
	char	*relative_path;
	void	*img;
	int		img_width;
	int		img_height;

	char teste[3] = "Cu";
	char teste2[3] = "Cu";
	relative_path = "./jump.xpm";
	read_map(argv[1]);
	printf("%s", ft_strjoin(teste, teste2));
	/*img_width = 32;
	img_height = 32;
	vars.mlx_ptr = mlx_init();
	vars.win_ptr = mlx_new_window(vars.mlx_ptr, 500, 500, "Hello World");
	img = mlx_xpm_file_to_image(vars.mlx_ptr, relative_path, &img_width, &img_height);
	//mlx_pixel_put(vars.mlx_ptr, vars.win_ptr, 250, 250, 0xFFFFFF);
	mlx_put_image_to_window(vars.mlx_ptr, vars.win_ptr, img, 250, 250);
	mlx_key_hook(vars.win_ptr, &deal_key, &vars); 
	mlx_loop(vars.mlx_ptr);*/
	return (0);
}
