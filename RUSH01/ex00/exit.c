/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   exit.c                                            :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: alpaz-pr <alpaz-pr@student.42madrid.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/08/23 15:59:07 by alpaz-pr         #+#    #+#              */
/*   Updated: 2026/08/23 18:08:05 by alpaz-pr        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	freese(int **b, int *v, int size)
{
	int	i;

	i = 0;
	if (v)
		free(v);
	if (!b)
		return ;
	while (i < size)
	{
		if (b[i])
			free(b[i]);
		i++;
	}
	if (b)
		free(b);
}

int	print_error(int **b, int *v, int size)
{
	freese(b, v, size);
	write(1, "Error\n", 6);
	return (1);
}
