/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 14:54:14 by momeaizi          #+#    #+#             */
/*   Updated: 2022/06/21 22:06:15 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	close_all(int size, int ***pipes)
{
	int	i;

	i = 0;
	while (++i < size)
		free((*pipes)[i - 1]);
	free(*pipes);
}
