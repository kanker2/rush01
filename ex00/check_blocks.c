/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_blocks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karce-ve <karce-ve@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 18:41:03 by karce-ve          #+#    #+#             */
/*   Updated: 2022/07/16 19:23:38 by karce-ve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_blocks_seen(int n_to_see, int nums[], int size)
{
	int	n_blocks_seen;
	int	i;
	int	max;

	max = 0;
	n_blocks_seen = 0;
	i = 0;
	while (i < size)
	{
		if (max < nums[i])
		{
			n_blocks_seen++;
			max = nums[i];
		}
		i++;
	}
	return (n_blocks_seen == n_to_see);
}

#include <stdlib.h>
#include <stdio.h>

int main()
{
	int nums[] = {1, 3, 2};
	int n_to_see = 2;
	int dim = 3;

	for(int i = 0; i < dim; i++)
		printf("%d, ", nums[i]);
	if(check_blocks_seen(n_to_see, nums, dim))
		printf("VAAAAAAA!!!\n");
	else
		printf("no va :(\n");
}

int	top_check(char **m, char *user_input, int dim)
{
	int	i;
	int	j;
	int	*n;
	int	user_n;
	int	valid;

	valid = 1;
	n = malloc(4 * dim);
	i = 0;
	while (valid && i < dim)
	{
		user_n = user_input[i] - '0';
		j = 0;
		while (j < dim)
		{
			n[j] = m[j][i];
			j++;
		}
		valid = check_blocks_seen(user_n, n, dim);
		i++;
	}
	free(n);
	return (valid);
}

int	down_check(char **m, char *user_input, int dim)
{
	int	i;
	int	j;
	int	*n;
	int	user_n;
	int	valid;

	valid = 1;
	n = malloc(4 * dim);
	i = dim;
	while (valid && i < 2 * dim)
	{
		user_n = user_input[i] - '0';
		j = 0;
		while (j < dim)
		{
			n[j] = m[dim - 1 - j][i];
			j++;
		}
		valid = check_blocks_seen(user_n, n, dim);
		i++;
	}
	free(n);
	return (valid);
}

int	left_check(char **m, char *user_input, int dim)
{
	int	i;
	int	j;
	int	*n;
	int	user_n;
	int	valid;

	valid = 1;
	n = malloc(4 * dim);
	i = 2 * dim;
	while (valid && i < 3 * dim)
	{
		user_n = user_input[i] - '0';
		j = 0;
		while (j < dim)
		{
			n[j] = m[i][j];
			j++;
		}
		valid = check_blocks_seen(user_n, n, dim);
		i++;
	}
	free(n);
	return (valid);
}

int	right_check(char **m, char *user_input, int dim)
{
	int	i;
	int	j;
	int	*n;
	int	user_n;
	int	valid;

	valid = 1;
	n = malloc(4 * dim);
	i = 3 * dim;
	while (valid && i < 4 * dim)
	{
		user_n = user_input[i] - '0';
		j = 0;
		while (j < dim)
		{
			n[j] = m[i][dim - 1 - j];
			j++;
		}
		valid = check_blocks_seen(user_n, n, dim);
		i++;
	}
	free(n);
	return (valid);
}
