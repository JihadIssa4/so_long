/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jissa <jissa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 11:58:54 by jissa             #+#    #+#             */
/*   Updated: 2025/07/10 14:34:47 by jissa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int	process_format(char letter, va_list ap)
{
	if (letter == 's')
		return (process_string(va_arg(ap, char *)));
	else if (letter == 'c')
		return (process_char(va_arg(ap, int)));
	else if (letter == 'i' || letter == 'd')
		return (process_int(va_arg(ap, int)));
	else if (letter == 'u')
		return (process_unsigned_int(va_arg(ap, unsigned int)));
	else if (letter == '%')
		return (process_mod(letter));
	else if (letter == 'p')
		return (process_vp(va_arg(ap, void *)));
	else if (letter == 'x')
		return (process_low_hex(va_arg(ap, unsigned int)));
	else if (letter == 'X')
		return (process_cap_hex(va_arg(ap, unsigned int)));
	return (1);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	ap;
	int		count;

	i = 0;
	count = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			count += process_format(format[i + 1], ap);
			i += 2;
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			count++;
			i++;
		}
	}
	va_end(ap);
	return (count);
}
