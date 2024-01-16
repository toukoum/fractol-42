/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atod.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 01:36:02 by rgiraud           #+#    #+#             */
/*   Updated: 2024/01/16 12:23:54 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static long	ft_atoi_boost(const char *str, int *error)
{
	int		i;
	int		sign;
	long	result;

	sign = 1;
	i = 0;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	if (!(str[i] >= '0' && str[i] <= '9'))
		*error = 1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - 48);
		i++;
		if ((result > INT_MAX && sign == 1) || (result > (2147483648) && sign
				== -1))
			*error = 1;
	}
	if (str[0] == '-' && str[1] == '0' && !result)
		*error = -1;
	return (result * sign);
}

double	atod(char *str, int *error, double len_dec)
{
	double	result;
	double	decimal;
	int		i;

	i = 0;
	result = 0;
	result += ft_atoi_boost(str, error);
	while (str[i] && !(str[i] == '.'))
		i++;
	if (str[i] == '.')
		i++;
	else
		return (result);
	if (!(str[i] >= '0' && str[i] <= '9'))
		*error = 1;
	decimal = ft_atoi_boost(str + i, error);
	while (str[i] && str[i++] == '0')
		len_dec *= 0.1;
	while (decimal > len_dec - 0.000001)
		decimal *= 0.1;
	if (result >= 0)
		return (result += decimal);
	return (result -= decimal);
}
