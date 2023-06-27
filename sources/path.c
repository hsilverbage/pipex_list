/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilverb <hsilverb@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 17:49:19 by hsilverb          #+#    #+#             */
/*   Updated: 2023/06/27 17:42:03 by hsilverb         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_init_path(char **envp, t_struct *pipex)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (envp[i][0] == 'P' && envp[i][1] == 'A' && envp[i][2] == 'T'
			&& envp[i][3] == 'H' && envp[i][4] == '=')
		{
			pipex->path = ft_split(envp[i] + 5, ':');
			return ;
		}
		i++;
	}
	ft_putstr_fd("Error : Path not found in environment\n", STDERR_FILENO);
	exit (EXIT_FAILURE);
}


void	ft_init_cmd_path(t_struct *pipex, int argc)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	pipex->cmd_path = ft_calloc(sizeof(char *), (argc -2));
	while (j < (argc - 3))
	{
		while (pipex->path[i])
		{
			if (access((pipex->cmd[j]), F_OK | X_OK) == 0)
			{
				pipex->cmd_path[j] = ft_strdup(pipex->cmd[j]);
				break;
			}
			pipex->cmd_path[j] = ft_strjoin_slash(pipex->path[i], pipex->cmd[j]);
			if (access((pipex->cmd_path[j]), F_OK | X_OK) == 0)
				break ;
			else
				free(pipex->cmd_path[j]);
			i++;
		}
		if (pipex->path[i] == NULL)
		{
			perror("Error");
			exit (EXIT_FAILURE);
		}
		i = 0;
		j++;
	}
	pipex->cmd_path[j] = NULL;
}


void	ft_init_option(t_struct *pipex, int argc)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	pipex->cmd_opt = ft_calloc(sizeof(char *), argc - 2);
	while (pipex->cmd[j])
	{
		if (pipex->cmd[j][i] == '-')
		{
			pipex->cmd_opt[j] = ft_strdup(pipex->cmd[j] + i);
			i = 0;
			j++;
		}
		else if (pipex->cmd[j][i] == '\0')
		{
			pipex->cmd[j] = NULL;
			i = 0;
			j++;
		}
		i++;
	}
	pipex->cmd_opt[j] = NULL;
}
void	ft_init_cmd(int argc, char **argv, t_struct *pipex)
{
	int	i;
	int j;

	j = 2;
	i = 0;
	pipex->cmd = ft_calloc(sizeof(char *), (argc -2));
	while (i < argc -3)
		pipex->cmd[i++] = argv[j++];
	pipex->cmd[i] = NULL;
}

void	ft_init_struct(int argc, char **argv, char **envp, t_struct *pipex)
{
	int	i;

	i = 0;
	pipex->nb_cmd = argc - 3;
	while (i <= pipex->nb_cmd)
	{
		ft_init_cmd(argc, argv, pipex);
		i++;
	}
	ft_init_path(envp, pipex);
	ft_init_cmd_path(pipex, argc);
	printf("KAPOUTE\n");
	ft_init_option(pipex, argc);
}

	// int i = 0;
	// while (pipex->cmd[i])
	// 	printf("%s\n", pipex->cmd[i++]);
	// while (pipex->path[i])
	// 	printf("%s\n", pipex->path[i++]);
	// i = 0;
	// i = 0;
	// while (pipex->cmd_path[i])
	// 	printf("%s\n", pipex->cmd_path[i++]);
	// i = 0;
	// while (pipex->cmd_opt[i])
	// 	printf("%s\n", pipex->cmd_opt[i++]);
