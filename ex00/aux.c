int comprobar(char **m, int i, int j, int dim)
{
	int row;
	int col;

	row = 0;
	while (row < dim && (row == i || m[row][j] != m[i][j]))
		row++;
	col = 0;
	while (col < dim && (col == j || m[i][col] != m[i][j]))
		col++;
	return (col == dim && row == dim);
}

int	aux(char **matrix, int i, int j, int dim)
{
	int	char_to_try;
	int have_solution;
	
	if(i == dim)
		return (1);
	else if(matrix[i][j] != '0')
	{
		if(j == dim - 1)
			return aux(matrix, i + 1, 0, dim);
		else
			return aux(matrix, i, j + 1, dim);
	}
	have_solution = 0;
  	char_to_try = 1;
	while(!have_solution && char_to_try <= dim)
	{
		matrix[i][j] = '0' + char_to_try;
		if(comprobar(matrix, i, j, dim))
		{
			if(j == dim - 1)
				have_solution = aux(matrix, i + 1, 0, dim);
			else
				have_solution = aux(matrix, i, j + 1, dim);
		}
		char_to_try++;
	}
	return (have_solution);
}

#include <stdio.h>
#include <stdlib.h>

void mostrar(char **m, int dim)
{
	for(int i = 0; i < dim; i++){
		for(int j = 0; j < dim; j++)
			printf("%c ", m[i][j]);
		printf("\n");
	}
}

int main()
{
	int size = 6;
	char **m = malloc(sizeof(char*) * size);
	int i = 0;
	while (i < size)
	{
		m[i] = malloc(size);
		i++;
	}

	int j;
	i = 0;

	while(i < size)
	{
		j = 0;
		while(j < size)
		{
			m[i][j] = '0';
			j++;
		}
		i++;
	}
	aux(m, 0, 0, size);
	mostrar(m, size);
}
