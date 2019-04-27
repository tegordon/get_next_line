/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tegordon <tegordon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 03:27:35 by tegordon          #+#    #+#             */
/*   Updated: 2019/04/26 20:55:24 by tegordon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void *content, size_t content_size)
{
	t_list	*new;

	if (!(new = malloc(sizeof(*new))))
		return (NULL);
	new->content = content;
	new->content_size = content_size;
	new->next = NULL;
	return (new);
}
