/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelidris <nelidris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 13:38:56 by nelidris          #+#    #+#             */
/*   Updated: 2021/12/21 15:57:36 by nelidris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

/*________________LINKED_LIST________________*/

typedef struct s_link
{
	int				index;
	struct s_link	*next;
}	t_list;

t_list	*ft_lstnew(int index);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_front(t_list **lst, t_list *e);
void	ft_lstadd_back(t_list **lst, t_list *e);
void	ft_lstclear(t_list **lst);

/*___________________LIBFT____________________*/

size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
long	ft_atoi(const char *str);
int		ft_isdigit(int c);

/*________________INSTRUCTIONS________________*/

void	e_swap(t_list	*e, char c);
void	e_push(t_list **e1, t_list **e2, char c);
void	e_rotate(t_list **e, char c);
void	e_reverse(t_list **e, char c);

/*___________________SORTING___________________*/

void	sort_stack_3(t_list	**stacks, int size);
void	sort_stacks_5(t_list **stacks, int size);
void	sort_stack_radix(t_list **stacks, int size);
t_list	*create_stack(int len, char **arr);
void	ft_stack_reedit(t_list **stacks, char **arr, int size);

/*___________________SORT_UTILS___________________*/

int		is_sorted(t_list	*a);
int		index_pos(t_list *a, int num);
int		fetch_num(t_list *a, char c);
int		before_last(t_list *a, int smallnum, int largenum);

/*___________________ERRORS___________________*/

int		is_error(int c, char **arr);
void	raise_error(void);

/*___________________BONUS___________________*/

# define BUFFER_SIZE 1024

char	*get_next_line(int fd);
void	read_instructions(t_list **stacks);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);

#endif