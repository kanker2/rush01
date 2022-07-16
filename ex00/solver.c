/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karce-ve <karce-ve@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 17:54:54 by karce-ve          #+#    #+#             */
/*   Updated: 2022/07/17 01:33:10 by karce-ve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	check_row_col(char **m, int i, int j, int dim)
{
	int	row;
	int	col;

	row = 0;
	while (row < dim && (row == i || m[row][j] != m[i][j]))
		row++;
	col = 0;
	while (col < dim && (col == j || m[i][col] != m[i][j]))
		col++;
	return (col == dim && row == dim);
}

int	user_input_check(char **m, char *user_input, int dim)
{
	int	t;
	int	d;
	int	l;
	int	r;

	t = top_check(m, user_input, dim);
	d = down_check(m, user_input, dim);
	l = left_check(m, user_input, dim);
	r = right_check(m, user_input, dim);
	return (t && d && l && r);
}

int	do_all(char **matrix, int i, int j, int dim)
{
	int	char_to_try;
	int	have_solution;
	int	row_sum;

	if (j == dim - 1)
		row_sum = 1;
	else
		row_sum = 0;
	if (i == dim)
		return (user_input_check(matrix, matrix[dim], dim));
	else if (matrix[i][j] != '0')
		return (do_all(matrix, i + row_sum, (j + 1) % dim, dim));
	have_solution = 0;
	char_to_try = 1;
	while (!have_solution && char_to_try <= dim)
	{
		matrix[i][j] = '0' + char_to_try;
		if (check_row_col(matrix, i, j, dim))
			have_solution = do_all(matrix, i + row_sum, (j + 1) % dim, dim);
		if (!have_solution)
			matrix[i][j] = '0';
		char_to_try++;
	}
	return (have_solution);
}

//void mostrar(char **m, int dim)
//{
//	for(int i = 0; i < dim; i++){
//		for(int j = 0; j < dim; j++)
//			printf("%c ", m[i][j]);
//		printf("\n");
//	}
//}
//
//int main()
//{
//	int size =8;
//	char **m = malloc(sizeof(char*) * size);
//	int i = 0;
//	while (i < size)
//	{
//		m[i] = malloc(size);
//		i++;
//	}
//
//	int j;
//	i = 0;
//
//	while(i < size)
//	{
//		j = 0;
//		while(j < size)
//		{
//			m[i][j] = '0';
//			j++;
//		}
//		i++;
//	}
//	mostrar(m, size);
//	aux(m, 0, 0, size);
//	mostrar(m, size);
//}
