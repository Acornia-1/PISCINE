/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdanielo <gdanielo@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 10:03:51 by gdanielo          #+#    #+#             */
/*   Updated: 2026/09/01 10:03:54 by gdanielo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	compare(char *s1, char *s2, int len1, int len2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if (len1 < len2)
		return (-s2[i]);
	else if (len1 > len2)
		return (s1[i]);
	else
		return (0);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	len1;
	int	len2;

	len1 = str_len(s1);
	len2 = str_len(s2);
	if (len1 == 0 && len2 == 0)
		return (0);
	else
	{
		if (len1 == 0 && len2 != 0)
			return (-s2[0]);
		else if (len1 != 0 && len2 == 0)
			return (s1[0]);
		else
		{
			return (compare(s1, s2, len1, len2));
		}
	}
}
