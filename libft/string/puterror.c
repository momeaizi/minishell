/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puterror.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 22:17:57 by momeaizi          #+#    #+#             */
/*   Updated: 2022/06/04 22:19:51 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void    puterror(char *name, char *error)
{
    write(2, name, ft_strlen(name));
    write(2, ": ", 2);
    write(2, error, ft_strlen(error));
    write(2, "\n", 1);
}