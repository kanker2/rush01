/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karce-ve <karce-ve@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 09:41:29 by karce-ve          #+#    #+#             */
/*   Updated: 2022/07/17 10:37:59 by karce-ve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "parse_input.h"
#include "print_matrix.h"
#include "solver.h"
#include "reset_pos.h"
#include <stdio.h>
char	**init_matrix(char *user_input, int dim);
void	free_matrix(char **matrix, int dim);
int		check_input(int argc);

int	main(int argc, char *argv[])
{
	char	**matrix;
	char	*user_input;
	int		dim;

	user_input = parse_input(argv[1], &dim);
	printf("%s\n", user_input);
	if (argc != 2 || user_input == 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	matrix = init_matrix(user_input, dim);
	if (!matrix)
	{
		free_matrix(matrix, dim);
		free(user_input);
		return (0);
	}
	if (solve(matrix, 0, 0, dim))
		print_matrix(matrix, dim);
	else
		write(1, "Error\n", 6);
	free_matrix(matrix, dim);
}

int	check_input(int argc)
{
	if (argc != 2)
		return (0);
	return (1);
}

char	**init_matrix(char *user_input, int dim)
{
	int		i;
	char	**matrix;

	matrix = malloc(sizeof (char *) * (dim + 1));
	matrix[dim] = user_input;
	i = 0;
	while (i < dim)
	{
		matrix[i] = malloc(dim);
		i++;
	}
	reset_pos(matrix, dim);
	return (matrix);
}

void	free_matrix(char **matrix, int dim)
{
	int	i;

	i = 0;
	free(matrix[dim]);
	while (i < dim)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}
