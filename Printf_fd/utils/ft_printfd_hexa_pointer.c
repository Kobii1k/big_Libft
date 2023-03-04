/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfd_hexa_pointer.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagne <mgagne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:45:11 by mgagne            #+#    #+#             */
/*   Updated: 2023/03/03 17:05:22 by mgagne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printfd.h"

static ssize_t	ft_loop_hexa(int fd, void *p)
{
	ssize_t		len;
	uintptr_t	nb;
	char		*base;

	base = "0123456789abcdef";
	nb = (uintptr_t)p;
	len = 0;
	if (nb >= 16)
	{
		len += ft_loop_hexa(fd, (void *)(nb / 16));
		len += ft_loop_hexa(fd, (void *)(nb % 16));
	}
	else
		len += ft_printfd_char(fd, base[nb]);
	return (len);
}

ssize_t	ft_printfd_hexa_pointer(int fd, void *p)
{
	ssize_t		len;

	len = write(fd, "0x", 2);
	len += ft_loop_hexa(fd, p);
	return (len);
}
