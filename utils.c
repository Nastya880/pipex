/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandroma <tandroma@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 13:55:18 by tandroma          #+#    #+#             */
/*   Updated: 2022/03/05 16:50:19 by tandroma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(char *message)
{
	perror(message);
	exit(1);
}

int	open_fd_in(char **argv)
{
	int	fd_in;

	fd_in = open(argv[1], O_RDWR);
	if (fd_in < 0)
		ft_error("Error");
	return (fd_in);
}

int	open_fd_out(char **argv)
{
	int	fd_out;

	fd_out = open(argv[4], O_RDONLY | O_WRONLY | O_TRUNC | O_CREAT, "rw");
	if (fd_out < 0)
		ft_error("Error");
	return (fd_out);
}

void	check_number_argc(int argc)
{
	if (argc != 5)
	{
		//perror("Example");
		write(1, "syntax error\n", 14);
		exit (1);
	}
}
