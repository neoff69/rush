/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgonnot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 20:10:01 by vgonnot           #+#    #+#             */
/*   Updated: 2022/07/17 20:21:20 by vgonnot          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"
#include <unistd.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

int main(int argc, char **argv)
{
	int	value_beginning[4][4];
	int	i;
	int	error;
	int result[4][4][4];
	int k;
	int j;

	error = 0;
	i = 0;
	k = 0;
	j = 0;
	ft_convert(argc, argv, &error, value_beginning);
	if (error == 1)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	check_value(result, value_beginning);
	while(i < 4)
	{
		while (j < 4)
		{
			while (k < 4)
			{
				ft_putchar(result[i][j][k] + '0');
				k++;
			}
			ft_putchar(' ');
			j++;
			k = 0;
		}
		i ++;
		j = 0;
		ft_putchar('\n');
	}
	return (0);
}

