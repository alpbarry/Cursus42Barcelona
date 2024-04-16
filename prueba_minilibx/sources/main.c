#include "../includes/libft.h"
#include "../mlx/mlx.h"
#include <stdlib.h>

#include <stdio.h>

int main( void ) {
	char *prueba = malloc(sizeof(char) * 5);
	prueba = "Hola";
	char *hola = ft_strdup(prueba);
	printf("Hola?? %s", hola);
	return (1);
}
