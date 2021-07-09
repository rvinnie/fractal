#include "fractol.h"

void	set_info(t_info *s_info, t_mand *t_mand, int x, int y)
{
	double	x_diff;
	double	y_diff;

	x_diff = 4 / (double)s_info->w;
	y_diff = 4 / (double)s_info->h;
	t_mand->a = x * x_diff - 2;
	t_mand->b = y * y_diff - 2;
	t_mand->start_a = t_mand->a;
	t_mand->start_b = t_mand->b;
}

void 	put_set(t_info *s_info, t_mand *s_mand, int x, int y)
{
	unsigned int	color;
	int				n;

	n = 0;
	while (n < s_info->max_iter)
	{
		s_mand->next_a = s_mand->a * s_mand->a - s_mand->b * s_mand->b;
		s_mand->next_b = 2 * s_mand->a * s_mand->b;
		s_mand->a = s_mand->next_a + s_mand->start_a;
		s_mand->b = s_mand->next_b + s_mand->start_b;
		if (abs(s_mand->a + s_mand->b)> 16)
			break ;
		n++;
	}
	color = n * 2 % 255;
	my_pxl_put(s_info->img, x, y, color);
	if (n == s_info->max_iter)
		my_pxl_put(s_info->img, x, y, COLOR_BLACK);
}

void	mandelbrot(t_info *s_info)
{
	t_mand	s_mand;
	int		x;
	int		y;

	y = 0;
	while (y < s_info->h)
	{
		x = 0;
		while (x < s_info->w)
		{
			set_info(s_info, &s_mand, x, y);
			put_set(s_info, &s_mand, x++, y);
		}
		y++;
	}
}
