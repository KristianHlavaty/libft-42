/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khlavaty <khlavaty@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 19:44:28 by khlavaty          #+#    #+#             */
/*   Updated: 2023/02/01 22:33:34 by khlavaty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	fts_len(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		len++;
		n = n * (-1);
	}
	while (n > 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char		*ptr;
	int			len;
	long int	m;

	len = fts_len(n);
	ptr = malloc(sizeof(char) * len + 1);
	if (!ptr)
		return (NULL);
	m = n;
	if (m < 0)
	{
		ptr[0] = '-';
		m = m * (-1);
	}
	ptr[len] = '\0';
	len--;
	if (m == 0)
		ptr[0] = '0';
	while (m)
	{
		ptr[len] = m % 10 + '0';
		m = m / 10;
		len--;
	}
	return (ptr);
}
