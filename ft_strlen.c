/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandroma <tandroma@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 16:25:50 by tandroma          #+#    #+#             */
/*   Updated: 2022/03/05 14:33:42 by tandroma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_strlen(const char *s)
{
	int	sz;
	int	i;

	i = 0;
	sz = 0;
	if (!s)
		return (7);
	while (s[i])
	{
		i++;
		sz++;
	}
	return (sz);
}
