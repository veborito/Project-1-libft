/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <bverdeci@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 09:58:46 by bverdeci          #+#    #+#             */
/*   Updated: 2023/04/13 19:29:26 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* Ajoute un pixel à l'image */
void	my_mlx_pixel_put(t_pixel *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

/* Dessine une ligne horizontale */
void	ft_draw_h(t_pixel *data, int x, int y, int len)
{
	int	i;

	i = x - 1;
	while (++i < len)
		my_mlx_pixel_put(data, i, y, 0x00FFFFFF);
}

/* Dessine une ligne verticale */
void	ft_draw_v(t_pixel *data, int x, int y, int len)
{
	int	i;

	i = y - 1;
	while (++i < len)
		my_mlx_pixel_put(data, x, i, 0x00FFFFFF);
}

/* Utilise l'algorithme de Bresenham pour dessiner un ligne */
void	ft_draw(t_pixel *img, t_point p1, t_point p2)
{
	int	x;
	int	y;
	int	dx;
	int	dy;
	int	p;

	x = p1.x;
	y = p1.y;
	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
	p = 2 * dy - dx;
	while (x <= p2.x)
	{
		my_mlx_pixel_put(img, x, y, 0x00FFFFFF);
		x++;
		if (p < 0)
			p = p + 2 * dy;
		else
		{
			p = p + 2 * dy - 2 * dx;
			y--;
		}
	}
}

int	main(int ac, char **av)
{
	int		fd;
	char	*line;
	void	*mlx;
	void	*mlx_win;
	t_pixel	img;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY, S_IRUSR | S_IWUSR);
		line = get_next_line(fd);
		mlx = mlx_init();
		mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, "FIL DE FER");
		img.img = mlx_new_image(mlx, WIDTH, HEIGHT);
		img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
				&img.line_length, &img.endian);
		mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
		mlx_loop(mlx);
	}
}
