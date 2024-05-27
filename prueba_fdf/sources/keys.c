#include "../includes/fdf.h"

void handle_z_scale_keys(int key, t_fdf **matrix)
{
    if (key == 91 || key == 28)
        (* matrix)->z_scale += 1;
    if (key == 84 || key == 19)
        (* matrix)->z_scale -= 1;
}

void handle_shift_keys(int key, t_fdf **matrix)
{
    if (key == '~')
        (* matrix)->shift_y -= 10;
    if (key == '}')
        (* matrix)->shift_y += 10;
    if (key == '{')
        (* matrix)->shift_x -= 10;
    if (key == '|')
        (* matrix)->shift_x += 10;
}

void handle_isometric_keys(int key, t_fdf **matrix)
{
    if (key == 49 || key == 87 || key == 23)
    {
        if ((*matrix)->is_isometric)
            (*matrix)->is_isometric = 0;
        else
            (*matrix)->is_isometric = 1;
    }
}

void handle_angle_keys(int key, t_fdf **matrix)
{
    if (key == 86 || key == 21)
        (* matrix)->angle += 0.05;
    if (key == 88 || key == 22)
        (* matrix)->angle -= 0.05;
}

void handle_scale_keys(int key, t_fdf **matrix)
{
    if (key == 24 || key == 69)
        (* matrix)->scale += 3;
    if (key == 27 || key == 78)
        (* matrix)->scale -= 3;
}