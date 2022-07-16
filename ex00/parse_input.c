/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmontes- <lmontes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 19:14:51 by lmontes-          #+#    #+#             */
/*   Updated: 2022/07/17 00:43:55 by karce-ve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

char	*parse_input(char *argv, int *input_size)
{
	int	i;
	int valid;
	int n;
	char *parsed_input;

	i = 0;
	n = 0;
	valid = 1;
	while (valid == 1  && argv[i] != '\0') //recorro el array inicial del parámetro de usuario
	{
		if(i%2==0)
		{
			valid = ('1' <= argv[i] && argv[i] <= 9); // comprueba que las posiciones pares son números
			n++; //aumenta el contador de números
		}
		else
			valid = (argv[i] = ' '); // comprueba posiciones  impares sean espacios
		i++;
	}
	if (!valid)
	   return (0);	
	*input_size = n;
    parsed_input = malloc(n);
	i = 0; //reiniciamos contadores
	n = 0;
	while (argv[i] != '\0') 
	{
		parsed_input[n] = argv[i]; //escribimos los números, en posiciones pares, en el nuevo array, que devolvemos
		n++;
		i = i + 2;
	}
	return (parsed_input); //devolvemos el puntero al nuevo array
}
/*
int    main(int argc, char *argv[])
{
	int size;

    size = 0;
	parse_input(*argv, &size);
}
*/
