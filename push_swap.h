/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:07:46 by andrefranci       #+#    #+#             */
/*   Updated: 2023/01/27 14:35:41 by abaiao-r         ###   ########.fr       */
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
	struct s_list	*next;
	struct s_list	*previous;
}					t_stack;

/* check_argv */

int					argv_is_number(char *argv);
int					argv_iszero(char *argv);
int					argv_duplicate(char **argv);
int					check_argv(char **argv);

/* check_argv_utils */

int					ft_error(void);
int					ft_isdigit(char c);
int					ft_issign(char c);
int					ft_atoi(const char *nptr);

/* check_argv_utils2 */

size_t				ft_strlen(const char *str);
void				*ft_calloc(size_t nmemb, size_t size);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				**ft_split(char const *s, char c);

/* ft_create_stack && ft_create_stack_utils.c */

t_stack				*ft_create_stack(char **argv);
t_stack				*ft_lstnew(int nbr);
void				ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack				*ft_lstlast(t_stack *lst);
void				ft_lstclear(t_stack **lst, void (*del)(void *));

#endif
