/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:07:46 by andrefranci       #+#    #+#             */
/*   Updated: 2023/01/24 15:33:47 by andrefranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	long long int	number;
	struct s_list	*next;
	struct s_list	*prev;
}					t_stack;

/* check_argv */

int	argv_is_number(char *argv);
int	argv_iszero(char *argv);
int	argv_duplicate(int argc, char **argv);
int	check_argv(char **argv);

/* check_argv_utils */

int	ft_error(void);
int	ft_isdigit(char c);
int	ft_issign(char c);
int	ft_atoi(const char *nptr);


#endif
