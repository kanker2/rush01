#include <stdio.h>
#include <stdlib.h>

int comprobar(char **m, int i, int j, int dim)
{
	int row;
	int col;
	printf("Comprobando:\nrow - %d ; col : %d --> %c\n", i, j, m[i][j]);
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
	int row_sum;
	
	if(j == dim - 1)
		row_sum = 1;
	else
		row_sum = 0;
	if(i == dim)
		return (1);
	else if(matrix[i][j] != '0')
		return aux(matrix, i + row_sum, (j + 1) % dim, dim);
	have_solution = 0;
  	char_to_try = 1;
	while(!have_solution && char_to_try <= dim)
	{
		matrix[i][j] = '0' + char_to_try;
		if(comprobar(matrix, i, j, dim))
		{
			printf("----DECIDIDO:-----------------------------\nrow - %d ; col : %d --> %c\n^^^^^^^^^^^^^^^^^^^^^^\n", i, j, matrix[i][j]);
			have_solution = aux(matrix, i + row_sum, (j + 1) % dim, dim);
		}
		else
			matrix[i][j] = '0';
		char_to_try++;
	}
	return (have_solution);
}

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
	int size =8;
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
	mostrar(m, size);
	aux(m, 0, 0, size);
	mostrar(m, size);
}
