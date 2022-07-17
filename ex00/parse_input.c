/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmontes- <lmontes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 19:14:51 by lmontes-          #+#    #+#             */
/*   Updated: 2022/07/17 18:04:17 by lmontes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	is_num(char c)
{
	return ('1' <= c && c <= '9');
}

char	*trim(char *str, int dim)
{
	int		i;
	int		n_nums;
	char	*nums;

	i = 0;
	n_nums = 0;
	nums = malloc(dim);
	while (str[i] != '\0')
	{
		if (is_num(str[i]))
			nums[n_nums++] = str[i];
		i++;
	}
	return (nums);
}

char	*parse_input(char *usr_input, int *dim_of_matrix)
{
	int	i;
	int	n_nums;
	int	valido;

	i = 0;
	n_nums = 0;
	valido = 1;
	*dim_of_matrix = 0;
	while (usr_input[i] != '\0' && valido)
	{
		valido = is_num(usr_input[i++]);
		if (valido)
			n_nums++;
		valido = (valido && (usr_input[i] == '\0' || usr_input[i++] == ' '));
	}
	valido = (valido && 0 == n_nums % 4);
	if (valido)
	{
		*dim_of_matrix = n_nums / 4;
		return (trim(usr_input, *dim_of_matrix));
	}
	else
		return (0);
}
