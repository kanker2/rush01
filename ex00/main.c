#include <stdlib.h>
#include <unistd.h>
#include "parse_input.h"
#include "print_matrix.h"
#include "solver.h"

//Quitar:
#include <stdio.h>

void init_matrix(char ***matrix, char *user_input, int dim);
void free_matrix(char **matrix, int dim);
int check_input(int argc);

int	main(int argc, char *argv[])
{
	char	**matrix;
	char	*user_input;
	int		dim;
	if(!check_input(argc))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	user_input = parse_input(argv[1], &dim);
	if (user_input == 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	printf("Despues de init guay user_input: %s, n: %d\n", user_input, dim);
	init_matrix(&matrix, user_input, dim);
	if(solve(matrix, 0, 0, dim))
		print_matrix(matrix, dim);
	else
		write(1, "Error\n", 6);

	free_matrix(matrix, dim);
}

int check_input(int argc)
{
	if(argc != 2)
		return (0);
	return (1);
}

void init_matrix(char ***matrix, char *user_input, int dim)
{
	int i;

	*matrix = malloc((sizeof(char*)) * (dim + 1));
	*matrix[dim] = user_input;
	i = 0;
	while(i < dim)
	{
		*matrix[i] = malloc(dim);
		i++;
	}
}

void free_matrix(char **matrix, int dim)
{
	int i;

	i = 0;
	free(matrix[dim]);
	while(i < dim)
	{
		free(matrix[i]);
		i++;
	}
}
