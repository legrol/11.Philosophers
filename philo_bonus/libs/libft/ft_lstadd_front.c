/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 14:01:42 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/08/24 14:01:42 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * The function "ft_lstadd_front" adds a new element at the beginning of a 
 * linked list. The new element becomes the new head of the list.
 * 
 * @param lst 			A pointer to the first element of the linked list. 
 *            			This pointer will be updated to point to the new 
 * 						element.
 * @param new 			A pointer to the new element to be added to the list.
 * 
 * @return None. 		The function modifies the linked list directly. 
 * 
 */

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst && !new)
		return ;
	new->next = *lst;
	*lst = new;
}
