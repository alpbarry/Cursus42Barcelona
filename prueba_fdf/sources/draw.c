#include "../includes/fdf.h"

float   mod(float i)
{
    return (i < 0 ? -i : i);
}

void    isometric(float *x, float *y, int z)
{
    *x = (*x - *y) * cos(0.8);
    *y = (*x + *y) * sin(0.8) - z;
}

void    bresenham(float x, float y, float x1, float y1, t_fdf *data)
{
    float   dx;
    float   dy;
    int     max;
    int     z;
    int     z1;
    
    z = data->z_matrix[(int)y][(int)x];
    z1 = data->z_matrix[(int)y1][(int)x1];
    x *= data->zoom;
    y *= data->zoom;
    x1 *= data->zoom;
    y1 *= data->zoom;
    data->color = (z || z1) ? 0xFF0000 : 0xFFFFFF;
    isometric(&x, &y, z);
    isometric(&x1, &y1, z1);
    x = data->shift_x;
    y = data->shift_y;
    x1 += data->shift_x;
    y1 += data->shift_y;
    dx = x1 - x;
    dy = y1 - y;
    max = MAX1(mod(dx), mod(dy));
    dx =/ MAX1(dx, dy);
    dy =/ MAX1(dx, dy);
    while ((int)(x - x1) || (int)(y - y1))
    {
        mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, 0xFFFFFF);
        x += dx;
        y += dy;
    }
}

void    draw(t_fdf *data)
{
    int x;
    int y;

    y = 0;
    while (y <= data->height)
    {
        x = 0;
        while (x < data->width)
        {
            if (x < data->width - 1)
                bresenham(x, y, x + 1, y, data);
            bresenham(x, y, x + 1, y, data);
            bresenham(x, y, x, y + 1, data);
            x++;
        }
    }

}