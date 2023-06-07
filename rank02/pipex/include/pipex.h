/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <bverdeci@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 12:11:03 by bverdeci          #+#    #+#             */
/*   Updated: 2023/06/07 18:53:00 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <stdio.h>
# include <sys/wait.h>

// ERROR

void	throw_error(void);

// file descriptors

typedef struct s_fds {
	int	infile;
	int	outfile;
	int	fd[2];
	int	res;
}	t_fds;

#endif