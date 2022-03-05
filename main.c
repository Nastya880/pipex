/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandroma <tandroma@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:33:24 by tandroma          #+#    #+#             */
/*   Updated: 2022/03/05 14:55:20 by tandroma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int	fd_in;
	int	fd_out;
	int	pid;
	int	fd[2];

	check_number_argc(argc);
	fd_in = open_fd_in(argv);
	fd_out = open_fd_out(argv);
	if (pipe(fd) != 0)
		ft_error("Error");
	pid = fork();
	if (pid == 0)
	{
		dup2(fd[1], 1);
		appear_child(fd_in, formed_cmd1(argv, ft_split(argv[2], ' '), envp),
			envp, ft_split(argv[2], ' '));
	}
	else if (pid == -1)
		ft_error("Error");
	parent_process(pid, fd_in, fd, fd_out);
	if (execve(formed_cmd2(argv, ft_split(argv[3], ' '), envp),
			ft_split(argv[3], ' '), envp) == -1)
		ft_error("Error");
	exit (0);
}
