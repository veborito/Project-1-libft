/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <bverdeci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:37:19 by bverdeci          #+#    #+#             */
/*   Updated: 2023/03/10 17:17:59 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Algos à tester:
	- quicksort
*/

void	ft_sort(t_list **s_a, t_list **s_b, t_result **res)
{
	int	median;

	median = ft_lstsize(*s_a) / 2;
	printf("%d\n", median);
	while (ft_lstsize(*s_a) > median - 1)
	{
		if ((*s_a)->index < median)
			ft_lstadd_back_2(res, ft_lstnew_2(ft_push_b(s_a, s_b)));
		printf("bug\n");
		break;
	}
}
