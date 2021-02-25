#include <mlx/mlx.h>
#include <math.h>

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_vars
{
	void	*mlx;
	void	*win;
}				t_vars;

void    		my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
/*
int				close(int keycode, t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
}
*/
void			draw_square(t_data *img, int x, int y, int size, int color)
{
	int		i;

	i = -1;
	while (++i < size)
	{
		my_mlx_pixel_put(img, x + i, y, color);
		my_mlx_pixel_put(img, x + i, y + size - 1, color);
	}
	i = size;
	while (--i > 0)
	{
		my_mlx_pixel_put(img, x, y + i, color);
		my_mlx_pixel_put(img, x + size - 1, y + i, color);
	}
}

void			draw_circle(t_data *img, int x, int y, int r, int color)
{
	int		a;
	int		b;

	a = x - r - 1;
	while (++a <= x + r)
	{
		b = y - r - 1;
		while (++b <= y + r)
		{
			if (pow(r, 2) <= pow(a - x, 2) + pow(b - y, 2) + 2000 && pow(r, 2) >= pow(a - x, 2) + pow(b - y, 2) - 100)
				my_mlx_pixel_put(img, x + a, y + b, color);
		}
	}
}

int				main(void)
{
	t_data	img;
	t_vars	vars;
	
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "cub3D");

	img.img = mlx_new_image(vars.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
//	draw_square(&img, 100, 100, 200, 0x00FF0000);
//	draw_circle(&img, 100, 100, 100, 0x000000FF);
//	draw_circle(&img, 220, 100, 100, 0x00FFFFFF);
//	draw_circle(&img, 340, 100, 100, 0x00FF0000);
//	draw_circle(&img, 160, 150, 100, 0x00FFE400);
//	draw_circle(&img, 280, 150, 100, 0x002F9D27);

	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	

//	mlx_key_hook(vars.win, close, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
