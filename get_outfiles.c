/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_outfiles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 21:33:45 by momeaizi          #+#    #+#             */
/*   Updated: 2022/06/05 21:44:26 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    get_outfiles(t_command *cmds)
{
    int i;
    int	fd;

	fd = -1;
	while (cmds)
	{
		i = -1;
		while (cmds->tokens->tokens[++i])
		{
			if (i && (!ft_strcmp(">", cmds->tokens->tokens[i - 1]) || !ft_strcmp(">>", cmds->tokens->tokens[i - 1])))
			{
				if (fd == -1)
					close(fd);
                if (!ft_strcmp(">", cmds->tokens->tokens[i - 1]))
				    fd = open(cmds->tokens->tokens[i], O_RDWR | O_CREAT);
                else
				    fd = open(cmds->tokens->tokens[i], O_RDWR | O_CREAT | O_APPEND);
				if (fd == -1 || access(cmds->tokens->tokens[i], F_OK))
					puterror(cmds->tokens->tokens[i], strerror(errno));
				else
					cmds->output = fd;
			}
		}
		cmds = cmds->next;
	}
}