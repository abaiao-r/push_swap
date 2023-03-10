/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:07:46 by andrefranci       #+#    #+#             */
/*   Updated: 2023/02/12 19:36:21 by andrefranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				number;
	int				rank;
	char			*rank_binary;

	struct s_list	*next;
}					t_stack;

/* arg_parser */
char				**ft_split(char const *s, char c);

/* check_argv */
int					argv_is_number(char *argv);
int					argv_duplicate(char **argv);
int					argv_is_int(char **argv);
int					check_argv(int argc, char **argv);

/* check_argv_utils */

int					ft_error(void);
int					ft_isdigit(char c);
int					ft_issign(char c);
long long			ft_atoll(const char *nptr);

/* check_argv_utils2 */
size_t				ft_strlen(const char *str);
void				*ft_calloc(size_t nmemb, size_t size);
char				*ft_substr(char const *s, unsigned int start, size_t len);
int					free_arguments_vector(char **arguments_vector);

/* ft_create_stack && ft_create_stack_utils.c && ft_create_stack_utils2.c*/

t_stack				*ft_create_stack(char **argv);
t_stack				*ft_lstnew(int nbr);
void				ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack				*ft_lstlast(t_stack *lst);
void				ft_lstclear(t_stack **lst);
t_stack				*ft_lst_before_last(t_stack *lst);
void				ft_lstadd_front(t_stack **lst, t_stack *new);
int					ft_lstsize(t_stack *lst);

/* movements */
/* swap_movements */
void				swap(t_stack **stack);
void				swap_a(t_stack **stack_a);
void				swap_b(t_stack **stack_b);
void				swap_s(t_stack **stack_a, t_stack **stack_b);

/* rotate_movements */
void				rotate(t_stack **stack);
void				rotate_a(t_stack **stack_a);
void				rotate_b(t_stack *stack_b);
void				rotate_r(t_stack *stack_a, t_stack *stack_b);

/* reverse_rotate_movements */
void				reverse_rotation(t_stack **stack);
void				reverse_rotation_a(t_stack **stack_a);
void				reverse_rotation_b(t_stack **stack_b);
void				reverse_rotation_r(t_stack **stack_a, t_stack **stack_b);

/* push_movements */
void				push(t_stack **stack_source, t_stack **stack_destination);
void				push_a(t_stack **stack_a, t_stack **stack_b);
void				push_b(t_stack **stack_a, t_stack **stack_b);

/* sort_stack && sort_stack2*/
void				sort_stack_n(t_stack **stack_a, t_stack **stack_b);
void				sort_stack_5(t_stack **stack_a, t_stack **stack_b);
void				sort_stack_4(t_stack **stack_a, t_stack **stack_b);
void				sort_stack_3(t_stack **stack_a);
void				sort_stack_2(t_stack **stack_a);
void				sort_stack(t_stack **stack_a, t_stack **stack_b);

/* sort_stack_utils */
t_stack				*rotate_to_lowest_number(t_stack *stack_a);
int					find_distance_top(t_stack *stack, int i);
int					find_lowest_number(t_stack *stack);
int					check_sorted(t_stack **stack_a);

/* sort_stack_utils2 */
int					count_digits_binary(int rank);
char				*convert_int_to_binary(int rank, int max);
int					assign_ranks(t_stack **stack_a);
#endif
