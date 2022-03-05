/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_path_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandroma <tandroma@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 08:31:49 by tandroma          #+#    #+#             */
/*   Updated: 2022/03/05 14:55:45 by tandroma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static	char	**find_path(char **argv, char **envp)
{
	char	**path;
	char	**env;
	int		i;

	i = -1;
	while (envp[++i])
	{
		env = ft_split(envp[i], '=');
		if (!ft_strncmp("PATH", env[0], 4))
		{
			if (env[1] == 0 && ft_strncmp(argv[2], "/", 1)
				&& ft_strncmp(argv[3], "/", 1))
				ft_error("Error");
			path = ft_split(env[1], ':');
			free(env);
			return (path);
		}
		free(env);
	}
	ft_error("Error");
	return (NULL);
}

static	int	check_path(char **path_cmd, char *cmd, char **path)
{
	int		i;
	char	*tmp;

	i = 0;
	while (path[i])
	{
		tmp = ft_strjoin(path[i], "/");
		tmp = ft_strjoin(tmp, cmd);
		if (open(tmp, O_RDONLY) != -1)
		{
			*path_cmd = tmp;
			cmd = tmp;
			return (1);
		}
		free(tmp);
		i++;
	}
	return (0);
}

char	*formed_cmd2(char **argv, char **cmd2, char **envp)
{
	char	*path_cmd2;
	char	**path;

	path_cmd2 = NULL;
	cmd2 = ft_split(argv[3], ' ');
	path = find_path(argv, envp);
	check_path(&path_cmd2, cmd2[0], path);
	if (path_cmd2 == NULL)
		ft_error("Error");
	return (path_cmd2);
}

char	*formed_cmd1(char **argv, char **cmd1, char **envp)
{
	char	*path_cmd1;
	char	**path;

	path_cmd1 = NULL;
	path = find_path(argv, envp);
	check_path(&path_cmd1, cmd1[0], path);
	if (path_cmd1 == NULL)
		ft_error("Error");
	return (path_cmd1);
}
