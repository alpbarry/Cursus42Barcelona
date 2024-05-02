#include    "../includes/fdf.h"

int deal_key(int key, void *data)
{
    ft_printf("key: %d\n", key);
    return (0);
}
/*
int main(int ac, char **av)
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
            ft_printf("%d ", data->z_matrix[i][j]);
            j++;
        }
        ft_printf("\n");
        i++;
    }
}*/

int main(int ac, char **av)
{
    t_fdf *data;

    data = (t_fdf*)malloc(sizeof(t_fdf));
    read_file(av[1], data);
    data->mlx_ptr = mlx_init();
    data->win_ptr = mlx_new_window(data->mlx_ptr, 1920, 1080, "fdf");
    bresenham(10, 10, 500, 200, data);
    mlx_key_hook(data->win_ptr, deal_key, NULL);
    mlx_loop(data->mlx_ptr);
     
}