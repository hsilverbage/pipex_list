/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilverb <hsilverb@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:22:34 by hsilverb          #+#    #+#             */
/*   Updated: 2023/06/27 18:13:55 by hsilverb         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>

typedef struct s_commands
{
	char	*path
	char	*cmd;
	char	*cmd_path;
	char	**cmd_opt;

}				t_commands

typedef struct s_struct
{
	int			infile;
	int			outfile;
	int			fd[2];
	int			nb_cmd;
	t_commands	*head;
}				t_struct;

void	ft_init_struct(int argc, char **argv, char **envp, t_struct *pipe);
void	ft_parsing(t_struct *pipe);
void	ft_free_all(t_struct *pipe);
void	ft_exec_first_child(t_struct *pipex);
void	ft_exec_second_child(t_struct *pipex);

char	*ft_strjoin_slash(char const *s1, char const *s2);

#endif
