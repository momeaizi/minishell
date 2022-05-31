/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 15:47:57 by momeaizi          #+#    #+#             */
/*   Updated: 2022/05/30 15:55:04 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


void    heredoc(char *limiter, int fd)
{
    char    *line;
    
    while (1)
    {
        line = readline("> ");
        if (!ft_strcmp(limiter, line))
            break ;
        write(fd, line, ft_strlen(line));
    }
}