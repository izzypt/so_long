
# MinilibX - Introduction

MiniLibx is a small library developed by 42. 

Provides an easy way to create graphical software, without any X-Window programming knowledge. 

It provides simple window creation, a drawing tool, image and basic events management.

I found most information to start on 42 docs :

https://harm-smits.github.io/42docs/

### About X-Window
X-Window is a network-oriented graphical system for unix. 

For example this is used when connecting to remote desktops. One of the most common examples of such implementation would be TeamViewer.

# Installation

- To get started setting up MiniLibx, I have downloaded the library from 42 paris :

https://github.com/42Paris/minilibx-linux

- Place the folder inside the root folder of your project repo.

- Next, follow the instruction and compile the MiniLibx with "make" or "./config".

After that, in the file you want to use MiniLibx on , you use ```#include "mlx_linux/mlx.h"```

- Also, keep in mind that when compiling you will have to use those flags :

```-Lmlx_linux/ -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz```


# Initialization

We must execute the mlx_init function to start. 

This will establish a connection to the correct graphical system and will return a void * which holds the location of our current MLX instance. To initialize MiniLibX one could do the following:

```
#include <mlx.h>

int	main(void)
{
	void	*mlx;

	mlx = mlx_init();
}
```
