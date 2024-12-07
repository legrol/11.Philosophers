/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 14:03:13 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/08/24 14:03:13 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * The function "ft_lstmap" iterates through a linked list and applies a given 
 * function to the content of each element, creating a new linked list with 
 * the results. If the allocation of a new element fails, the delete function 
 * is used to free the allocated memory, and the function returns NULL.
 * 
 * @param lst 			A pointer to the first element of the linked list to be
 * 						iterated.
 * @param f 			A function pointer to a function that is applied to the 
 * 						content of each element in the list.
 * @param del 			A function pointer to a delete function that is used to
 * 						free the content of elements in case of failure.
 * 
 * @return 				A pointer to the first element of the newly created 
 * 						linked list. 
 *         				Returns NULL if an allocation fails or if the input 
 * 						list is NULL.
 * 
 */

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	void	*set;

	if (!lst || !f || !del)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		set = f(lst->content);
		new_node = ft_lstnew(set);
		if (!new_node)
		{
			del(set);
			ft_lstclear(&new_list, (*del));
			return (new_list);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}
