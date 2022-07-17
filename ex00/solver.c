/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karce-ve <karce-ve@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 17:54:54 by karce-ve          #+#    #+#             */
/*   Updated: 2022/07/17 18:06:05 by lmontes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "check_blocks.h"

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

int	solve(char **matrix, int i, int j, int dim)
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
		return (solve(matrix, i + row_sum, (j + 1) % dim, dim));
	have_solution = 0;
	char_to_try = 1;
	while (!have_solution && char_to_try <= dim)
	{
		matrix[i][j] = '0' + char_to_try;
		if (check_row_col(matrix, i, j, dim))
			have_solution = solve(matrix, i + row_sum, (j + 1) % dim, dim);
		if (!have_solution)
			matrix[i][j] = '0';
		char_to_try++;
	}
	return (have_solution);
}
