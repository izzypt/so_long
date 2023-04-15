#include "so_long.h"


int	validate_map(char **map, s_map_data *map_info)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	printf("The map has %d lines\n", map_info->num_of_lines);
	while (i <= map_info->num_of_lines)
	{
		while(map[i][j]!= '\0')
		{
			if (i == 0 && map[i][j] != 1)
			{
				perror("Error in map. First line must be a wall");
				return (0);
			}
			else if (map[i][0] == 1)
			{
				perror("Error in map. First column must be a wall");
			}
		}
		i++;
	}
	return (1);
}

char **create_matrix(int fd)
{
	s_map_data	*map_data;
	char	**matrix;
	int		i;
	int		j;

	i = 0;
	j = 0;
	map_data = malloc(sizeof(s_map_data) + 1);
	matrix = malloc(sizeof(char*) * 1000);
	if (matrix == NULL)
	{
        perror("malloc failed to allocate memory for the map matrix");
        exit(1);
    }
	while (1)
	{
		matrix[i] = get_next_line(fd);
		if (matrix[i] == NULL)
		{
			map_data->num_of_lines = i;
			break;
		}
		i++;
	}
	validate_map(matrix, map_data);
	return (matrix);
}

int main(int argc, char **argv)
{
    int fd;
	void	*mlx;
	void	*window;

	if (argc < 2)
	{
		perror("Please provide a map\n");
		return (0);
	}
    fd = open(argv[1], O_RDONLY);
	create_matrix(fd);
	/*mlx = mlx_init();
	window = mlx_new_window(mlx, 500, 500, "Hello world!");
	mlx_loop(mlx);*/
}