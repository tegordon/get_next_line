/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tegordon <tegordon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 09:24:00 by tegordon          #+#    #+#             */
/*   Updated: 2019/03/27 23:40:09 by tegordon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	- appends a copy of the null-terminated string _s2 to the end of the
**  null-terminated string _s1, then adds a terminating '\0'.
**
**  - appends not more than _n characters from _s2.
**
**	- string _s1 must have sufficient space to hold the result.
*/

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t i;

	i = ft_strlen(s1);
	while (*s2 && n-- > 0)
		s1[i++] = *s2++;
	s1[i] = '\0';
	return (s1);
}
