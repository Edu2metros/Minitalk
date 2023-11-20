/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eddos-sa <eddos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 12:45:28 by eddos-sa          #+#    #+#             */
/*   Updated: 2023/11/18 13:37:20 by eddos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	unsigned int	i;
	int				sign;
	int				result;

	i = 0;
	sign = 1;
	result = 0;
	sign = ((str[i] == '+' || ft_isdigit(str[i])) - (str[i] == '-'));
	if ((str[i] == '+') || (str[i] == '-'))
		i++;
	while (str[i] != '\0' && ft_isdigit(str[i]) && str[i] != '.')
		result = result * 10 + (str[i++] - '0');
	return (result * sign);
}
