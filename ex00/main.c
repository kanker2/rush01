#include <stdlib.h>

void init_matrix(char **matrix, char *user_input, int dim);

int	main(int argc, char *argv[])
{
	char	**matrix;
	char	*user_input;
	int		dim;
	user_input = parse_input(argv[1], &dim);
	if (user_input == 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	init_matrix(matrix, user_input, dim);
	if(logica_del_programa(matrix, 0, 0, dim))
		mostrar(matrix, dim);
	else
		write(1, "Error\n", 6);

	free_matrix(matrix, dim);
}

void init_matrix(char **matrix, char *user_input, int dim)
{
	int i;

	matrix = malloc((sizeof(char*)) * (dim + 1));
	matrix[dim] = user_input;
	i = 0;
	while(i < dim)
	{
		matrix[i] = malloc(dim);
		i++;
	}
}
