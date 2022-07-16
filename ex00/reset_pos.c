/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_pos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolliot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 13:21:53 by ncolliot          #+#    #+#             */
/*   Updated: 2022/07/16 14:29:14 by ncolliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	reset_pos(char *m[], int dim)
{
	int i;
	int j;
	
	i  = 0;
	while (i < dim)
	{
		j = 0;
		while (j < dim)
		{
			m[i][j] = '0';
			j++;
		}
		i++;
	}
}

