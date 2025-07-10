/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jissa <jissa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 16:45:11 by jissa             #+#    #+#             */
/*   Updated: 2025/06/03 18:32:50 by jissa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

char	*ft_utoa(unsigned int n)
{
	char			*res;
	int				len;
	unsigned int	temp;

	len = 0;
	temp = n;
	if (n == 0)
		len = 1;
	while (temp)
	{
		temp /= 10;
		len++;
	}
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	res[len] = '\0';
	if (n == 0)
		res[0] = '0';
	while (n)
	{
		res[--len] = (n % 10) + '0';
		n /= 10;
	}
	return (res);
}

int	process_int(int num)
{
	char	*res;
	int		len;

	res = ft_itoa(num);
	if (!res)
		return (0);
	ft_putstr_fd(res, 1);
	len = ft_strlen(res);
	free(res);
	return (len);
}

int	process_unsigned_int(unsigned int num)
{
	char	*res;
	int		len;

	res = ft_utoa(num);
	ft_putstr_fd(res, 1);
	len = ft_strlen(res);
	free (res);
	return (len);
}
