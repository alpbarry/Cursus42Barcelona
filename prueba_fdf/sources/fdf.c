#include    "../includes/fdf.h"

int deal_key(int key, void *data)
{
    ft_printf("key: %d\n", key);
    return (0);
}

int main(int ac, char **av)
{
    fdf *data;
    int i;
    int j;

    data = (fdf*)malloc(sizeof(fdf));
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
        i++;
    }
}