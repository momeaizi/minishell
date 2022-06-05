/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_infiles.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 21:49:58 by momeaizi          #+#    #+#             */
/*   Updated: 2022/06/05 21:34:16 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    get_infiles(t_command *cmds)
{
    int i;
    int	fd;

	fd = -1;
	while (cmds)
	{
		i = -1;
		while (cmds->tokens->tokens[++i])
		{
			if (i && !ft_strcmp("<", cmds->tokens->tokens[i - 1]))
			{
				if (fd == -1)
					close(fd);
				fd = open(cmds->tokens->tokens[i], O_RDONLY);
				if (fd == -1 || access(cmds->tokens->tokens[i], F_OK))
					puterror(cmds->tokens->tokens[i], strerror(errno));
				else
				{
					if (i > cmds->tokens->index)
						cmds->input = fd;
				}
			}
		}
		cmds = cmds->next;
	}
}