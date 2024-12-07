/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 14:03:29 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/08/24 14:03:29 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * The function "ft_lstnew" creates a new element for a linked list. The 
 * content of the new element is initialized with the provided value, and its 
 * next pointer is set to NULL.
 * 
 * @param content 			A pointer to the content to be stored in the new 
 * 							element.
 * 
 * @return 					A pointer to the newly created linked list element.
 * 							Returns NULL if the memory allocation fails.
 * 
 */

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *) malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}
