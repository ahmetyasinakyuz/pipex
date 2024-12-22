/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakyuz <aakyuz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:52:38 by aakyuz            #+#    #+#             */
/*   Updated: 2024/12/21 12:24:17 by aakyuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <fcntl.h>
# include <sys/wait.h>
# include <errno.h>
# include <string.h>

typedef struct s_pipex
{
	int		fd_in;
	int		fd_out;
	char	*path1;
	char	*path2;
	char	**cmd1;
	char	**cmd2;
}			t_pipex;

char		*path_finder(char *cmd, char **envp);
void		free_all(t_pipex *pip);
#endif