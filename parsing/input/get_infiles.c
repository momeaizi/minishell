/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_infiles.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 21:49:58 by momeaizi          #+#    #+#             */
/*   Updated: 2022/06/23 18:57:10 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	open_infile(t_command *cmd, char *infile, int i)
{
	int	fd;

	fd = open(infile, O_RDONLY);
	if (fd == -1)
	{
		cmd->error = 1;
		puterror(cmd->tokens->tokens[i], strerror(errno));
	}
	if (i > cmd->tokens->index && fd != -1)
	{
		if (cmd->input != 0)
			close(cmd->input);
		cmd->input = fd;
	}
	else if (fd != -1)
		close(fd);
}

void	get_infile(t_command *cmds, char *file, int i)
{
	if (i && !p_ft_strcmp("<", cmds->tokens->tokens[i - 1]))
	{
		if (!p_ft_strlen(file))
		{
			puterror(cmds->tokens->tokens[i], "ambiguous redirect");
			cmds->error = 1;
		}
		else
			open_infile(cmds, file, i);
	}
}
