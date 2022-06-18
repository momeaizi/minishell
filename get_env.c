/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 16:59:28 by momeaizi          #+#    #+#             */
/*   Updated: 2022/06/18 18:43:38 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*p_ft_getenv(char *var, char **env)
{
	int		i;
	int		len;

	i = -1;
	len = p_ft_strlen(var);
	while (env[++i])
		if (!p_ft_strncmp(env[i], var, len) && env[i][len] == '=')
			return (p_ft_strdup(env[i] + len + 1));
	return (NULL);
}
