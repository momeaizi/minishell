/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 15:47:57 by momeaizi          #+#    #+#             */
/*   Updated: 2022/06/02 16:13:46 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


void    heredoc(t_command *commands, char **env)
{
    int			i;
	t_command	*tmp;

	tmp = commands;
	while (tmp)
	{
		i = -1;
		while (tmp->tokens->tokens[++i])
		{
			if (i > 1 && !ft_strcmp("<<", tmp->tokens->tokens[i - 1]) && !redirect(tmp->tokens->tokens[i]) && !redirect(tmp->tokens->tokens[i - 2]))
			{
				printf("%s\n", tmp->tokens->tokens[i]);
			}
		}
		tmp = tmp->next;
	}
}




    // char    *line;
    
    // while (1)
    // {
    //     line = readline("> ");
    //     if (!ft_strcmp(limiter, line))
    //         break ;
    //     write(fd, line, ft_strlen(line));
    // }