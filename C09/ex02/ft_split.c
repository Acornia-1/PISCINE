/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdanielo <gdanielo@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 03:49:04 by gdanielo          #+#    #+#             */
/*   Updated: 2026/08/31 03:49:07 by gdanielo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_is_in_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_cwords(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (!(ft_is_in_charset(str[i], charset)) && i == 0)
			count++;
		else if (!(ft_is_in_charset(str[i], charset))
			&& ft_is_in_charset(str[i - 1], charset))
			count++;
		i++;
	}
	return (count);
}

int	ft_clet(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (!(ft_is_in_charset(str[i], charset)) && str[i])
	{
		i++;
		count++;
	}
	return (count);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	**ft_split(char *str, char *charset)
{
	int		si;
	int		li;
	int		i;
	char	**result;

	si = 0;
	li = 0;
	result = (char **) malloc((ft_cwords(str, charset) + 1) * sizeof(char *));
	while (si < ft_cwords(str, charset) && str[li])
	{
		while (ft_is_in_charset(str[li], charset) && str[li])
			li++;
		i = li;
		result[si] = (char *) malloc(ft_clet(&str[li], charset) + 1);
		while (!ft_is_in_charset(str[li], charset) && str[li])
		{
			result[si][li - i] = str[li];
			li++;
		}
		result[si][li - i] = '\0';
		si++;
	}
	result[ft_cwords(str, charset)] = NULL;
	return (result);
}
