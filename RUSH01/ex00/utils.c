/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   utils.c                                           :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: alpaz-pr <alpaz-pr@student.42madrid.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/08/22 12:25:21 by alpaz-pr         #+#    #+#              */
/*   Updated: 2026/08/23 18:07:45 by alpaz-pr        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	error(int argc, char **argv, int size)
{
	int	i;

	i = 0;
	if (argc != 2)
		return (write(1, "Error\n", 6), 1);
	while (argv[1][i] != '\0')
	{
		if ((i % 2 == 0) && (argv[1][i] < '1' || argv[1][i] > (size + '0')))
			return (write(1, "Error\n", 6), 1);
		if ((i % 2 != 0) && (argv[1][i] != ' '))
			return (write(1, "Error\n", 6), 1);
		i++;
	}
	return (0);
}

void	print_board(int **b, int size)
{
	int		r;
	char	l;
	int		c;

	r = 0;
	while (r < size)
	{
		c = 0;
		while (c < size)
		{
			l = b[r][c] + '0';
			write(1, &l, 1);
			if (c != (size - 1))
				write(1, " ", 1);
			c++;
		}
		write(1, "\n", 1);
		r++;
	}
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	**start(int size)
{
	int	i;
	int	j;
	int	**board;

	board = malloc(size * sizeof(int *));
	if (!board)
		return (NULL);
	i = 0;
	while (i < size)
	{
		board[i] = malloc(size * sizeof(int));
		if (!board[i])
			return (NULL);
		j = 0;
		while (j < size)
		{
			board[i][j] = 0;
			j++;
		}
		i++;
	}
	return (board);
}

int	ft_check_dup(int **b, int size)
{
	int	r;
	int	c;
	int	k;

	r = 0;
	while (r < size)
	{
		c = 0;
		while (c < size)
		{
			k = c + 1;
			while (k < size)
			{
				if (b[r][c] != 0 && b[r][c] == b[r][k])
					return (0);
				if (b[c][r] != 0 && b[c][r] == b[k][r])
					return (0);
				k++;
			}
			c++;
		}
		r++;
	}
	return (1);
}
