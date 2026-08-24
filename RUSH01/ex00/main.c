/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   main.c                                            :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: alpaz-pr <alpaz-pr@student.42madrid.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/08/22 11:45:25 by alpaz-pr         #+#    #+#              */
/*   Updated: 2026/08/23 15:44:53 by alpaz-pr        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	print_board(int **b, int size);
int		error(int argc, char **argv, int size);
int		ft_strlen(char *str);
int		ft_up(int **b, int c, int view, int size);
int		ft_down(int **b, int c, int view, int size);
int		ft_right(int **b, int r, int view, int size);
int		ft_left(int **b, int r, int view, int size);
int		ft_check_dup(int **b, int size);
int		print_error(int **b, int *v, int size);
int		ft_check_dup(int **b, int size);
int		ft_left_partial(int **b, int r, int c, int view);
int		ft_up_partial(int **b, int r, int c, int view);
int		**start(int size);
void	ft_n(int **b, int *view, int size);
void	freese(int **b, int *v, int size);

int	ft_valid(int **b, int pos, int *view, int size)
{
	int	i;
	int	col;
	int	row;

	row = pos / size;
	col = pos % size;
	i = 0;
	while (i < size)
	{
		if (i != col && b[row][col] == b[row][i])
			return (0);
		if (i != row && b[row][col] == b[i][col])
			return (0);
		i++;
	}
	if (row == (size - 1) && !ft_up(b, col, view[col], size))
		return (0);
	if (row == (size - 1) && !ft_down(b, col, view[col + size], size))
		return (0);
	if (col == (size - 1) && !ft_left(b, row, view[(2 * size) + row], size))
		return (0);
	if (col == (size - 1) && !ft_right(b, row, view[(3 * size) + row], size))
		return (0);
	return (1);
}

int	ft_solve(int **b, int pos, int *view, int size)
{
	int	i;
	int	col;
	int	row;

	row = pos / size;
	col = pos % size;
	if (row == size)
		return (1);
	if (b[row][col] != 0)
		return (ft_solve(b, pos + 1, view, size));
	i = 1;
	while (i <= size)
	{
		b[row][col] = i;
		if (ft_left_partial(b, row, col, view[(2 * size) + row])
			&& ft_up_partial(b, row, col, view[col])
			&& ft_valid(b, pos, view, size) == 1)
		{
			if (ft_solve(b, pos + 1, view, size))
				return (1);
		}
		b[row][col] = 0;
		i++;
	}
	return (0);
}

int	*load_view(char *argv, int size)
{
	int	i;
	int	k;
	int	*tab;

	i = 0;
	k = 0;
	tab = (int *) malloc(sizeof(int) * (size * 4));
	if (!tab)
		return (NULL);
	while (argv[i] != '\0' && k < (size * 4))
	{
		tab[k] = argv[i] - '0';
		i += 2;
		k++;
	}
	return (tab);
}

int	count_size(char *argv)
{
	int	i;

	i = 0;
	while (argv[i] != '\0')
	{
		if (i % 2 == 0)
		{
			if (!(argv[i] >= '0' && argv[i] <= '9'))
				return (-42);
		}
		i++;
	}
	i++;
	if (i % 4 != 0)
		return (-42);
	if ((i / 2) % 4 != 0 || ((i / 2) / 4) > 9)
		return (-42);
	return ((i / 2) / 4);
}

int	main(int argc, char **argv)
{
	int	**board;
	int	*view;
	int	size;

	if (argc >= 2)
	{
		size = count_size(argv[1]);
		if (error(argc, argv, size))
			return (1);
		if (size == -42)
			return (print_error(NULL, NULL, size));
		view = load_view(argv[1], size);
		if (!view)
			return (print_error(NULL, view, size));
		board = start(size);
		if (!board)
			return (print_error(board, view, size));
		ft_n(board, view, size);
		if (!ft_check_dup(board, size)
			|| !ft_solve(board, 0, view, size))
			return (print_error(board, view, size));
		print_board(board, size);
		return (freese(board, view, size), 0);
	}
	return (1);
}
