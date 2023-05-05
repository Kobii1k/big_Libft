/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfd_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagne <mgagne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:44:29 by mgagne            #+#    #+#             */
/*   Updated: 2023/05/05 14:51:44 by mgagne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_printfd_str(int fd, char *s)
{
	if (s)
		return (write(fd, s, ft_strlen(s)));
	return (write(fd, "(null)", 6));
}
