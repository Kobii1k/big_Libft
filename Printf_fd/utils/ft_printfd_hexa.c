/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfd_hexa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagne <mgagne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:44:58 by mgagne            #+#    #+#             */
/*   Updated: 2023/03/03 17:04:21 by mgagne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printfd.h"

ssize_t	ft_printfd_hexa(int fd, int n, char *base)
{
	unsigned int	nb;
	ssize_t			len;

	len = 0;
	nb = n;
	if (nb >= 16)
	{
		len += ft_printfd_hexa(fd, (int)(nb / 16), base);
		len += ft_printfd_hexa(fd, (int)(nb % 16), base);
	}
	else
		len += ft_printfd_char(fd, base[nb]);
	return (len);
}
