#include "../mlx/mlx.h"
#include "../includes/libft.h"
#include "../ft_printf/ft_printf.h"
#include "../includes/fdf.h"
#include <math.h>

int deal_key(int key, t_fdf *data)
{
    printf("key: %d\n", key);
    if (key == 126)
        data->shift_y -= 10;
    if (key == 125)
        data->shift_y += 10;
    if (key == 123)
        data->shift_x -= 10;
    if (key == 124)
        data->shift_x += 10;
    mlx_clear_window(data->mlx_ptr, data->win_ptr);
    draw(data);
    return (0);
}

/*int main(int ac, char **av)
{
    t_fdf *data;
    int i;
    int j;

    data = (t_fdf*)malloc(sizeof(t_fdf));
    read_file(av[1], data);

    i = 0;
    while (i < data->height)
    {
        j = 0;
        while (j < data->width)
        {
            printf("%d ", data->z_matrix[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
}*/

int main(int ac, char **av)
{
    t_fdf *data;

    if (ac != 2)
    {
        ft_printf("Usage: ./fdf [map]\n");
        return (0);
    }
    data = (t_fdf*)malloc(sizeof(t_fdf));
    read_file(av[1], data);
    data->mlx_ptr = mlx_init();
    data->win_ptr = mlx_new_window(data->mlx_ptr, 1920, 1080, "fdf");
    //bresenham(10, 10, 500, 200, data);
    data->zoom = 30;
    draw(data);
    mlx_key_hook(data->win_ptr, deal_key, NULL);
    mlx_loop(data->mlx_ptr);
}
