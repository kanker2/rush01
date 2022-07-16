/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmontes- <lmontes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 13:52:16 by lmontes-          #+#    #+#             */
/*   Updated: 2022/07/16 17:29:18 by lmontes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_matrix(char **matrix, int dim)
{
	int	i;
	int	j;

	i = 0;
	while (i < dim)
	{
		j = 0;
		while (j < dim)
		{
			write(1, &(matrix[i][j]), 1);
			write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
