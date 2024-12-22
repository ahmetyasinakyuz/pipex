/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakyuz <aakyuz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 12:26:43 by aakyuz            #+#    #+#             */
/*   Updated: 2024/12/21 15:00:30 by aakyuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	cmd_open(t_pipex *pip, char **argv, char **envp)
{
	pip->cmd1 = ft_split(argv[2], ' ');
	pip->cmd2 = ft_split(argv[3], ' ');
	pip->path1 = path_finder(pip->cmd1[0], envp);
	pip->path2 = path_finder(pip->cmd2[0], envp);
	pip->fd_in = -1;
	pip->fd_out = -1;
	pip->fd_in = open(argv[1], O_RDONLY);
	pip->fd_out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (pip->fd_in < 0 || pip->fd_out < 0)
	{
		ft_printf("No such file or directory\n");
		free_all(pip);
		exit(2);
	}
	if (!pip->path1 || !pip->path2)
	{
		ft_printf("Error: command not found\n");
		free_all(pip);
		exit(127);
	}
}

void	child_process(t_pipex *pip, int *pipe_fd, char **envp)
{
	close(pipe_fd[0]);
	dup2(pip->fd_in, STDIN_FILENO);
	dup2(pipe_fd[1], STDOUT_FILENO);
	close(pipe_fd[1]);
	execve(pip->path1, pip->cmd1, envp);
	ft_printf("Error: execve failed\n");
	free_all(pip);
	exit(1);
}

void	parent_process(t_pipex *pip, int *pipe_fd, char **envp, pid_t pid)
{
	close(pipe_fd[1]);
	dup2(pipe_fd[0], STDIN_FILENO);
	dup2(pip->fd_out, STDOUT_FILENO);
	close(pipe_fd[0]);
	waitpid(pid, NULL, 0);
	execve(pip->path2, pip->cmd2, envp);
	ft_printf("Error: execve failed\n");
	free_all(pip);
	exit(1);
}

void	execute_commands(t_pipex *pip, char **envp)
{
	int		pipe_fd[2];
	pid_t	pid;

	if (pipe(pipe_fd) == -1)
	{
		ft_printf("Error: pipe failed\n");
		free_all(pip);
		exit(1);
	}
	pid = fork();
	if (pid == -1)
	{
		ft_printf("Error: fork failed\n");
		free_all(pip);
		exit(1);
	}
	if (pid == 0)
		child_process(pip, pipe_fd, envp);
	else
		parent_process(pip, pipe_fd, envp, pid);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pip;

	if (argc != 5)
	{
		ft_printf("Error: Wrong number of arguments\n");
		exit(1);
	}
	cmd_open(&pip, argv, envp);
	execute_commands(&pip, envp);
	free_all(&pip);
}
