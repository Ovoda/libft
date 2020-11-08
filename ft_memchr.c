/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 12:58:25 by calide-n          #+#    #+#             */
/*   Updated: 2020/11/05 13:09:22 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	uc;
	void			*str;

	uc = c;
	str = (void *)s;
	while (*(unsigned char *)str != uc && str && --n)
		str++;
	if (uc == *(unsigned char *)str)
		return (str);
	return (0);
}
