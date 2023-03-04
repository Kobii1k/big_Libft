/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagne <mgagne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:01:45 by mgagne            #+#    #+#             */
/*   Updated: 2023/03/04 12:19:56 by mgagne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printfd.h"

ssize_t	ft_print_conversionfd(int fd, char c, va_list args)
{
	if (c == 'c')
		return (ft_printfd_char(fd, va_arg(args, int)));
	if (c == 's')
		return (ft_printfd_str(fd, va_arg(args, char *)));
	if (c == 'p')
		return (ft_printfd_hexa_pointer(fd, va_arg(args, void *)));
	if (c == 'd')
		return (ft_printfd_int(fd, va_arg(args, int)));
	if (c == 'i')
		return (ft_printfd_int(fd, va_arg(args, int)));
	if (c == 'u')
		return (ft_printfd_uint(fd, va_arg(args, unsigned int)));
	if (c == 'x')
		return (ft_printfd_hexa(fd, va_arg(args, int), "0123456789abcdef"));
	if (c == 'X')
		return (ft_printfd_hexa(fd, va_arg(args, int), "0123456789ABCDEF"));
	if (c == '%')
		return (ft_printfd_char(fd, '%'));
	return (0);
}

ssize_t	ft_convert_strfd(int fd, const char *format, va_list args)
{
	ssize_t	i;
	ssize_t	len;

	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			len += ft_print_conversionfd(fd, format[i], args);
		}
		else if (format[i] != '%')
			len += ft_printfd_char(fd, format[i]);
		i++;
	}
	return (len);
}

int	ft_printfd(int fd, const char *format, ...)
{
	ssize_t	len;
	va_list	args;

	len = write(fd, 0, 0);
	if (len < 0)
		return (-1);
	va_start(args, format);
	len = ft_convert_strfd(fd, format, args);
	va_end(args);
	return (len);
}
