/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilverb <hsilverb@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:21:14 by hsilverb          #+#    #+#             */
/*   Updated: 2023/06/27 18:46:08 by hsilverb         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


void	ft_check_args(int argc, char **envp)
{
	if (argc < 5)
	{
		ft_putstr_fd("Error : Too few arguments\n", STDERR_FILENO);
		exit (EXIT_FAILURE);
	}
	if (!envp[0])
	{
		ft_putstr_fd("Error : Environment not found\n", STDERR_FILENO);
		exit (EXIT_FAILURE);
	}
}

void	ft_open_fd(int argc, char **argv, t_struct *pipex)
{
	pipex->infile = open(argv[1], O_RDONLY);
	pipex->outfile = open(argv[argc -1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (pipex->infile < 0 || pipex->outfile < 0)
	{
		perror("Error");
		exit (EXIT_FAILURE);
	}
}
t_commands	ft_new_node(t_commands *cmds, int argc, char **argv, int i)
{
	t_commands	*new;

	new = malloc(sizeof(t_commands));
	if (!new)
	{
		ft_free_all(&pipex);
		ft_printf("Error : malloc fucked up\n");
		exit (EXIT_FAILURE);
	}
	new->cmd = argv[i];
	new->path = ft_init_path();
	new->cmd_path = ft_init_path_cmd();
	new->cmd_opt = ft_init_option();
	new->next = NULL;
}

void	ft_init_struct(t_struct *pipex, int argc, char **argv)
{
	int			i;

	i = 0;
	ft_bzero(&pipex, sizeof(t_struct));
	ft_open_fd(argc, argv, &pipex);
	pipex->nb_cmd = argc - 3;

}

int	main(int argc, char **argv, char **envp)
{
	t_struct	pipex;

	ft_check_args(argc, envp);
	ft_init_struct(&pipex, argc, argv);

	// ft_init_struct(argc, argv, envp, &pipex);
	// if (pipe(pipex.fd) < 0)
	// {
	// 	perror("Error :");
	// 	ft_free_all(&pipex);
	// }
	// pipex.pid1 = fork();
	// if (pipex.pid1 == 0)
	// 	ft_exec_first_child(&pipex);
	// waitpid(pipex.pid1, NULL, 0);
	// pipex.pid2 = fork();
	// waitpid(pipex.pid2, NULL, 0);
	// if (pipex.pid2 == 0)
	// 	ft_exec_second_child(&pipex);
	// ft_free_all(&pipex);
	return (0);
}
