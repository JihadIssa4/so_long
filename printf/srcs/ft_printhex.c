/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jissa <jissa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 16:42:38 by jissa             #+#    #+#             */
/*   Updated: 2025/06/03 18:32:53 by jissa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void	ft_putstr_cap_fd(char *s, int fd)
{
	int		i;
	char	*copy;

	copy = ft_strdup(s);
	i = 0;
	if (!copy)
		return ;
	while (copy[i])
	{
		if (copy[i] >= 'a' && copy[i] <= 'f')
		{
			copy[i] -= 32;
		}
		i++;
	}
	ft_putstr_fd(copy, fd);
	free(copy);
}

char	*utoa_hex(unsigned long num)
{
	char			*res;
	char			*hex_chars;
	int				len;
	unsigned long	tmp;

	hex_chars = "0123456789abcdef";
	len = 1;
	tmp = num;
	while (tmp >= 16)
	{
		tmp /= 16;
		len++;
	}
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	res[len] = '\0';
	while (len--)
	{
		res[len] = hex_chars[num % 16];
		num /= 16;
	}
	return (res);
}

int	process_vp(void *ptr)
{
	unsigned long	addr;
	char			*hex_str;
	int				len;

	addr = (unsigned long)ptr;
	if (ptr == NULL)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	ft_putstr_fd("0x", 1);
	len = 2;
	if (!ptr)
	{
		ft_putstr_fd("0", 1);
		return (len + 1);
	}
	hex_str = utoa_hex(addr);
	if (!hex_str)
		return (0);
	ft_putstr_fd(hex_str, 1);
	len += ft_strlen(hex_str);
	free(hex_str);
	return (len);
}

int	process_low_hex(unsigned int num)
{
	char	*hex_str;
	int		len;

	len = 0;
	hex_str = utoa_hex(num);
	if (!hex_str)
		return (0);
	ft_putstr_fd(hex_str, 1);
	len += ft_strlen(hex_str);
	free(hex_str);
	return (len);
}

int	process_cap_hex(unsigned int num)
{
	char	*hex_str;
	int		len;

	len = 0;
	hex_str = utoa_hex(num);
	if (!hex_str)
		return (0);
	ft_putstr_cap_fd(hex_str, 1);
	len += ft_strlen(hex_str);
	free(hex_str);
	return (len);
}
