/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 14:01:29 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/08/24 14:01:29 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * The function "ft_lstadd_back" adds a new element to the end of a linked list.
 * If the list is empty, the new element becomes the first element of the list.
 * 
 * @param lst 			A pointer to the first element of the linked list. 
 *            			If the list is empty, this pointer will be updated to 
 * 						point to the new element.
 * @param new 			A pointer to the new element to be added to the list.
 * 
 * @return None. 		The function modifies the linked list directly.
 * 
 */

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!lst || !new)
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}
