/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedperei <pedperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:02:08 by pedperei          #+#    #+#             */
/*   Updated: 2023/01/05 21:16:55 by pedperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

long int			ft_atoi(const char *str);
void				*ft_calloc(size_t nitems, size_t size);
int					ft_isdigit(int c);
int					ft_strcmp(const char *str1, const char *str2);
char				**ft_split(char const *s, char c);
int					check_argv_type(char **argv);
int					check_argv_dups(char **argv);
char				**arg_parser(int argc, char **argv);
int					count_args(char **args);
int					free_args(char **args, int n_args, int flag);

typedef struct s_list
{
	int				num;
	int				index;
	int				rank;
	char			*rank_bin;
	struct s_list	*next;

}					t_int_node;

void				ft_lstdelone(t_int_node *lst);
void				push(t_int_node **stack_1, t_int_node **stack_2);
void				swap(t_int_node **stack);
t_int_node			*ft_new_t_int_node(long int num, int index);
void				ft_lstadd_back(t_int_node **lst, t_int_node *new);
void				ft_lstadd_front(t_int_node **lst, t_int_node *new);
t_int_node			*search_node(t_int_node **node, int index);
int					ft_lstsize(t_int_node *lst);
void				ft_lstclear(t_int_node **stack);
void				rotate(t_int_node **stack);
void				reverse_rotate(t_int_node **stack);
void				refresh_index(t_int_node **stack);
int					count_digits_binary(int num);
char				*convert_binary(int num, int max);
int					rank_stack(t_int_node **stack);
int					is_sorted(t_int_node **stack);
void				sort_2(t_int_node **stack_a, t_int_node **stack_b);
void				sort_3(t_int_node **stack_a, t_int_node **stack_b);
void				sort_4(t_int_node **stack_a, t_int_node **stack_b);
void				sort_5(t_int_node **stack_a, t_int_node **stack_b);
void				radix_sort(t_int_node **stack_a, t_int_node **stack_b);
void				sort_final(t_int_node **stack_a, t_int_node **stack_b);
void				swap_p(t_int_node **stack_a, t_int_node **stack_b, char c);
void				push_p(t_int_node **stack_1, t_int_node **stack_2, char c);
void				rotate_p(t_int_node **stack_a, t_int_node **stack_b,
						char c);
void				r_rotate_p(t_int_node **stack_a, t_int_node **stack_b,
						char c);

#endif
