/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandroma <tandroma@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 13:59:34 by tandroma          #+#    #+#             */
/*   Updated: 2022/03/05 14:48:33 by tandroma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h> //free
# include <unistd.h> //dup2(int fildes, int fildes2);
# include <fcntl.h> //open
# include <stdio.h> //perror     perror(const char *s);

/*
** libft functions
*/

int		ft_strncmp(char *s1, char *s2, int n);
size_t	ft_strlen(char const *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);

/*
** operations for work processes
*/

void	parent_process(int pid, int fd_in, int *fd, int fd_out);
void	appear_child(int fdin, char *pathcmd1, char **envp, char **cmd1);
char	*formed_cmd1(char **argv, char **cmd1, char **envp);
char	*formed_cmd2(char **argv, char **cmd2, char **envp);
void	ft_error(char *message);
void	check_number_argc(int argc);
int		open_fd_in(char **argv);
int		open_fd_out(char **argv);

#endif
