#include "../includes/fdf.h"

float   mod(float i)
{
    return (i < 0 ? -i : i);
}
void    bresenham(float x, float y, float x1, float y1, t_fdf *data)
{
    float   dx;
    float   dy;
    int     max;

    dx = x1 - x;
    dy = y1 - y;
    max = MAX1(mod(dx), mod(dy));
    dx =/ MAX1(dx, dy);
    dy =/ MAX1(dx, dy);
    while (1)
    {
        mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, 0xFFFFFF);
        x += dx;
        y += dy;
    }
}