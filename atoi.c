/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgonnot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 08:41:00 by vgonnot           #+#    #+#             */
/*   Updated: 2022/07/16 17:17:52 by vgonnot          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int *ft_convert(int argc, char **argv, int *error)
{
	int	i;
	int	j;
	int	*tab;

	tab = malloc(sizeof(int) * 16);
	i = 0;
	j = 0;
	if (argc != 2)
	{
		*error = 1;
		return (0);
	}
	while (argv[i])
	{
		if (((argv[i] < '1' || argv[i] > '4') && argv[i] != ' ')
			|| (argv[i] == ' ' && argv[i - 1] == ' ') || i > 31) 
		{
			*error = 1;
			return (0);
		}
		if (argv[i] >= '1' && argv[i] <= '4')
		{
			tab[j] = argv[i] - '0';
			j++;
		}	
		i++;
	}
	if (i != 31)
	{
		*error = 1;
		return (0);
	}
	return (tab);
}

int main(int argc, char **argv)
{
	int	*value_beginning;
	int	i;
	int	error;
	int 	result[4][4];

	error = 0;
	i = 0;
	value_beginning = ft_convert(argc, argv[1], &error);
	if (error == 1)
	{
		write(1, "Error\n", 6);
		return 0;
	}
	while(i < 16)
	{
		
	}
	free(value_beginning);
	return (0);
}
