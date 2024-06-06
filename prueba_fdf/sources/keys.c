#include "../includes/fdf.h"

void	handle_z_scale_keys(int key, t_fdf **matrix)
{
	if (key == KEY_8 || key == KEY_8T)
		(*matrix)->z_scale += 1;
	if (key == KEY_2 || key == KEY_2T)
		(*matrix)->z_scale -= 1;
}

void	handle_shift_keys(int key, t_fdf **matrix)
{
	if (key == KEY_UP)
		(*matrix)->shift_y -= 10;
	if (key == KEY_DOWN)
		(*matrix)->shift_y += 10;
	if (key == KEY_LEFT)
		(*matrix)->shift_x -= 10;
	if (key == KEY_RIGHT)
		(*matrix)->shift_x += 10;
}

void	handle_isometric_keys(int key, t_fdf **matrix)
{
	if (key == KEY_SPACE || key == KEY_5 || key == KEY_5T)
	{
		if ((*matrix)->is_isometric)
			(*matrix)->is_isometric = 0;
		else
			(*matrix)->is_isometric = 1;
	}
}

void	handle_angle_keys(int key, t_fdf **matrix)
{
	if (key == KEY_4 || key == KEY_4T)
		(*matrix)->angle += 0.05;
	if (key == KEY_6 || key == KEY_6T)
		(*matrix)->angle -= 0.05;
}

void	handle_scale_keys(int key, t_fdf **matrix)
{
	if (key == KEY_P || key == KEY_PT)
		(*matrix)->scale += 3;
	if (key == KEY_M || key == KEY_MT)
		(*matrix)->scale -= 3;
}
