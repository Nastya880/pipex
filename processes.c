/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandroma <tandroma@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 13:54:33 by tandroma          #+#    #+#             */
/*   Updated: 2022/03/05 14:48:37 by tandroma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	appear_child(int fd_in, char *path_cmd1, char **envp,
			char **cmd1)
{
	dup2(fd_in, 0);
	if (execve(path_cmd1, cmd1, envp) == -1)
		ft_error("Error");
	exit(0);
}

void	parent_process(int pid, int fd_in, int *fd, int fd_out)
{
	waitpid(pid, 0, 0);
	close(fd_in);
	close(fd[1]);
	dup2(fd[0], 0);
	dup2(fd_out, 1);
	close(fd_out);
	close(fd[0]);
}
