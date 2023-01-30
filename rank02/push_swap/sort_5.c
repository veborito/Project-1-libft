/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <bverdeci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 18:31:57 by bverdeci          #+#    #+#             */
/*   Updated: 2023/01/30 13:50:12 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_min_pos	ft_minimum(t_list *stk_a)
{
	t_list		*tmp;
	t_list		*stk;
	t_min_pos	minimum;

	tmp = stk_a;
	stk = stk_a;
	minimum.min = tmp->content;
	while (tmp != NULL)
	{
		if (minimum.min > tmp->content)
			minimum.min = tmp->content;
		tmp = tmp->next;
	}
	minimum.pos = 0;
	while (stk != NULL)
	{
		if (minimum.min == stk->content && stk != NULL)
			return (minimum);
		(minimum.pos)++;
		stk = stk->next;
	}
	return (minimum);
}

/*trouver les deux plus petits nombres et les faire passer sur la stack b, 
sort la stack a avec le sort3 algo et repush sur a*/

void	ft_sort5(t_list **s_a, t_list **s_b, t_result **res)
{
	t_min_pos	minimum;

	while (ft_lstsize(*s_b) < ft_lstsize(*s_a) / 2)
	{
		minimum = ft_minimum(*s_a);
		while (minimum.min != (*s_a)->content)
		{
			if (minimum.pos >= (ft_lstsize(*s_a) / 2))
			{
				ft_lstadd_back_2(res, ft_lstnew_2(ft_reverse_rotate_a(s_a)));
			}
			else
				ft_lstadd_back_2(res, ft_lstnew_2(ft_swap_a(s_a)));
		}
		ft_lstadd_back_2(res, ft_lstnew_2(ft_push_b(s_a, s_b)));
	}
	ft_sort3(s_a, res);
	while (ft_lstsize(*s_b) > 0)
		ft_lstadd_back_2(res, ft_lstnew_2(ft_push_a(s_b, s_a)));
}
