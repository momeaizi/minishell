/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 18:35:52 by momeaizi          #+#    #+#             */
/*   Updated: 2022/05/28 18:35:53 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	clear(char **paths, int *size, int j)
{
	while (--j >= 0)
		free(paths[j]);
	free(paths);
	if (size)
		free(size);
}
