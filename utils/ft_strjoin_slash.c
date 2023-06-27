/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_slash.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilverb <hsilverb@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 14:10:49 by hsilverb          #+#    #+#             */
/*   Updated: 2023/06/22 14:23:57 by hsilverb         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strjoin_slash(char const *s1, char const *s2)
{
	size_t		i;
	size_t		j;
	char		*s3;

	i = 0;
	j = 0;
	s3 = ft_calloc(sizeof(char), (ft_strlen(s1) + ft_strlen(s2) + 2));
	if (s3 == NULL)
		return (NULL);
	while (s1 && s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	s3[i++] = '/';
	while (s2 && s2[j] && s2[j] != ' ')
		s3[i++] = s2[j++];
	s3[i] = '\0';
	return (s3);
}
