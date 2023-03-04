/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfd.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagne <mgagne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:01:56 by mgagne            #+#    #+#             */
/*   Updated: 2023/03/03 17:02:19 by mgagne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTFD_H
# define FT_PRINTFD_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>

int		ft_printfd(int fd, const char *format, ...);

ssize_t	ft_printfd_char(int fd, int c);
ssize_t	ft_printfd_str(int fd, char *s);
ssize_t	ft_printfd_int(int fd, int n);
ssize_t	ft_printfd_uint(int fd, unsigned int nb);
ssize_t	ft_printfd_hexa(int fd, int n, char *base);
ssize_t	ft_printfd_hexa_pointer(int fd, void *p);
size_t	ft_strlen(const char *s);

#endif
