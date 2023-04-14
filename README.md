
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

After that, in the file you want to use MiniLibx on , you use ```#include "mlx_linux/mlx.h"``` or ```#include <mlx.h>``` (try one or the other)

- Also, keep in mind that when compiling you will have to use those flags :

```gcc <yourfile>.c -Lmlx_linux/ -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz```


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
# Minilibx - The key functions

- ```mlx_init()```
  - This will establish a connection to the correct graphical system and will return a void * which holds the location of our current MLX instance.
  -  Exemplo :
  ```
	int	main(void)
	{
		void	*mlx;

		mlx = mlx_init();
	}
  ```
- ```mlx_new_window()``` 
  - It will return a pointer to the window we have just created. 
  - We can give the window height, width and a title.
  - Exemplo :
  ```
    mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
  ```
- ```mlx_destroy_window()```  
  - Is responsible for freeing all the ressources that have been allocated for the window when it is no longer needed.
  - Exemplo :
  ```
    mlx_destroy_window(mlx_ptr, win_ptr);
  ```
- ```mlx_destroy_display()``` 
  - Use it to destroy the display before using ```free()``` on the ```mlx_init()``` pointer.
  - Exemplo :
  ```
    mlx_destroy_display(mlx_ptr);
  ``` 
- ```mlx_loop()```
  - This loop will keep our mlx instance running and waiting for inputs.
  ```
	mlx_loop(mlx);
  ```
# Writing pixels to a image 

First of all, we should start by understanding what type of image ```mlx``` requires. 

If we initiate an image, we will have to pass a few pointers to which it will write a few important variables. 

The first one is the ```bpp```, also called the ```bits per pixel```. 

As the pixels are basically ints, these usually are 4 bytes, however, this can differ if we are dealing with a small endian (which means we most likely are on a remote display and only have 8 bit colors).

Now we can initialize the image with size 1920×1080 as follows:
