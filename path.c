/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakyuz <aakyuz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 13:16:49 by aakyuz            #+#    #+#             */
/*   Updated: 2024/12/21 14:09:35 by aakyuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_paths(char **paths)
{
	int	i;

	i = 0;
	while (paths[i])
	{
		free(paths[i]);
		i++;
	}
	free(paths);
}

char	*find_path_in_paths(char *cmd, char **paths)
{
	char	*tmp;
	char	*path;
	int		i;

	i = 0;
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	return (NULL);
}

char	**get_paths_from_env(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (ft_split(envp[i] + 5, ':'));
		i++;
	}
	return (NULL);
}

char	*path_finder(char *cmd, char **envp)
{
	char	**paths;
	char	*path;

	paths = get_paths_from_env(envp);
	if (!paths)
		return (NULL);
	path = find_path_in_paths(cmd, paths);
	free_paths(paths);
	return (path);
}

void	free_all(t_pipex *pip)
{
	int	i;

	i = 0;
	while (pip->cmd1 && pip->cmd1[i])
		free(pip->cmd1[i++]);
	free(pip->cmd1);
	i = 0;
	while (pip->cmd2 && pip->cmd2[i])
		free(pip->cmd2[i++]);
	free(pip->cmd2);
	free(pip->path1);
	free(pip->path2);
	if (pip->fd_in > 0)
		close(pip->fd_in);
	if (pip->fd_out > 0)
		close(pip->fd_out);
}
