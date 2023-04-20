/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagalha <smagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 12:13:29 by simao             #+#    #+#             */
/*   Updated: 2023/04/20 19:11:35 by smagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

size_t	ft_decimal_places(int n)
{
	size_t	decimal_places;

	decimal_places = 0;
	if (n == 0)
		return (1);
	else if (n < 0)
		decimal_places = decimal_places + 1;
	while (n != 0)
	{
		n = n / 10;
		decimal_places++;
	}
	return (decimal_places);
}

char	*ft_itoa(int nb)
{
	char		*str;
	size_t		len;
	long int	n;

	n = nb;
	len = ft_decimal_places(n);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	while (n != 0)
	{
		len--;
		str[len] = n % 10 + '0';
		n = n / 10;
	}
	return (str);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	x;

	if (little[0] == '\0')
		return ((char *)big);
	i = 0;
	while (i < len && big[i] != '\0')
	{
		x = 0;
		while (little[x] == big[i + x] && (i + x) < len)
		{
			if (little[x + 1] == '\0')
				return ((char *)&big[i]);
			x++;
		}
		i++;
	}
	return (0);
}

void	set_portal_cord(int i, int j)
{
	portal()->x = i;
	portal()->y = j;
}
