/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilverb <hsilverb@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 17:48:46 by hsilverb          #+#    #+#             */
/*   Updated: 2023/06/27 15:32:31 by hsilverb         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_close_fd(t_struct *pipex)
{
	close(pipex->infile);
	close(pipex->outfile);
}

void	ft_free_all2(t_struct *pipex)
{
	int	i;

	i = 0;
	if (pipex->cmd_opt)
	{
		while (i < pipex->nb_cmd)
			free(pipex->cmd_opt[i++]);
		free(pipex->cmd_opt);
		i = 0;
	}
}

void	ft_free_all(t_struct *pipex)
{
	int	i;

	i = 0;
	if (pipex->path)
	{
		while (pipex->path[i])
			free(pipex->path[i++]);
		free(pipex->path);
		i = 0;
	}
	if (pipex->cmd)
		free(pipex->cmd);
	if (pipex->cmd_path)
	{
		while (pipex->cmd_path[i])
			free(pipex->cmd_path[i++]);
		free(pipex->cmd_path);
	}
	ft_free_all2(pipex);
	ft_close_fd(pipex);
}
