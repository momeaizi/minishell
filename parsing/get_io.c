/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_io.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:19:50 by momeaizi          #+#    #+#             */
/*   Updated: 2022/06/23 18:57:14 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_io(t_command *cmds)
{
	char	*file;
	int		i;

	while (cmds)
	{
		i = -1;
		while (cmds->tokens->tokens[++i] && !cmds->error)
		{
			if (i && redirect(cmds->tokens->tokens[i - 1]) && \
			p_ft_strcmp(cmds->tokens->tokens[i - 1], "<<"))
			{
				file = remove_quotes(expand_var(\
				p_ft_strdup(cmds->tokens->tokens[i]), 0));
				get_outfile(cmds, file, i);
				get_infile(cmds, file, i);
				free(file);
			}
		}
		cmds = cmds->next;
	}
}
