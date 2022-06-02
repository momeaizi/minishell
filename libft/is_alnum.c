/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_alnum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 18:52:15 by momeaizi          #+#    #+#             */
/*   Updated: 2022/05/30 22:18:59 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}


int	ft_isnum(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_isalnum(char c)
{
	if (ft_isalpha(c) || ft_isnum(c))
		return (1);
	return (0);
}