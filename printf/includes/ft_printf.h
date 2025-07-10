/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jissa <jissa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 16:28:19 by jissa             #+#    #+#             */
/*   Updated: 2025/06/03 12:35:53 by jissa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int	ft_printf(const char *format, ...);
int	process_char(char c);
int	process_string(char *str);
int	process_int(int num);
int	process_unsigned_int(unsigned int num);
int	process_mod(char mod);
int	process_vp(void *ptr);
int	process_low_hex(unsigned int num);
int	process_cap_hex(unsigned int num);

#endif