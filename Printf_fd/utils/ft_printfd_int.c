/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfd_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagne <mgagne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:44:46 by mgagne            #+#    #+#             */
/*   Updated: 2023/03/03 17:04:14 by mgagne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printfd.h"

ssize_t	ft_printfd_int(int fd, int n)
{
	long	nb;
	ssize_t	len;

	len = 0;
	nb = n;
	if (nb < 0)
	{
		nb *= -1;
		len += write(fd, "-", 1);
	}
	if (nb >= 10)
	{
		len += ft_printfd_int(fd, (int)(nb / 10));
		len += ft_printfd_int(fd, (int)(nb % 10));
	}
	else
		len += ft_printfd_char(fd, nb + '0');
	return (len);
}
