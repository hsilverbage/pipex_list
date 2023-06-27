/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_children.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilverb <hsilverb@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 17:54:57 by hsilverb          #+#    #+#             */
/*   Updated: 2023/06/27 15:36:03 by hsilverb         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_exec_first_child(t_struct *pipex)
{
	close(pipex->fd[1]);
	execv(pipex->cmd_path[0], 	(char *[]) {pipex->cmd[0], pipex->cmd_opt[0], NULL});
	perror("echec de exevc");
	exit(EXIT_FAILURE);
}

void	ft_exec_second_child(t_struct *pipex)
{
	close(pipex->fd[0]);
	execv(pipex->cmd_path[1], 	(char *[]) {pipex->cmd[1], pipex->cmd_opt[1], NULL});
	perror("echec de exevc");
	exit(EXIT_FAILURE);
}
