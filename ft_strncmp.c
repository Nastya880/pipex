/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandroma <tandroma@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 16:27:27 by tandroma          #+#    #+#             */
/*   Updated: 2022/03/05 14:34:37 by tandroma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strncmp(char *s1, char *s2, int n)
{
	size_t			i;
	unsigned char	*mys1;
	unsigned char	*mys2;

	i = 0;
	mys1 = (unsigned char *)s1;
	mys2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (mys1[i] && mys2[i] && mys1[i] == mys2[i] && n > 1)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		n--;
		i++;
	}
	return (mys1[i] - mys2[i]);
}
