/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 14:02:05 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/08/24 14:02:05 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * The function "ft_lstclear" deletes and frees all elements of a linked list 
 * using the provided delete function. The pointer to the list is set to NULL 
 * after all elements are deleted.
 * 
 * @param lst 			A pointer to the first element of the linked list. 
 *						The pointer is updated to NULL after the list is 
 * 						cleared.
 * @param del 			A function pointer to a delete function that is used to 
 * 						free the content of each element in the list.
 * 
 * @return None. 		The function modifies the linked list directly.
 * 
 */

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (!lst || !del)
		return ;
	if (lst)
	{
		while (*lst)
		{
			tmp = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = tmp;
		}
	}
}
