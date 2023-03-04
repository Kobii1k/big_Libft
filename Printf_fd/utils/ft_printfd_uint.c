/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfd_uint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagne <mgagne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:44:18 by mgagne            #+#    #+#             */
/*   Updated: 2023/03/04 12:21:01 by mgagne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printfd.h"

ssize_t	ft_printfd_uint(int fd, unsigned int nb)
{
	ssize_t	len;

	len = 0;
	if (nb >= 10)
	{
		len += ft_printfd_uint(fd, nb / 10);
		len += ft_printfd_uint(fd, nb % 10);
	}
	else
		len += ft_printfd_char(fd, nb + '0');
	return (len);
}
