/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 22:54:33 by pvillena          #+#    #+#             */
/*   Updated: 2022/05/30 19:59:45 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <limits.h>
# include <stdarg.h>
# define BUFFER_SIZE 1

int		ft_isalpha(int nbr);
int		ft_isdigit(int nbr);
int		ft_isalnum(int nbr);
int		ft_isascii(int nbr);
int		ft_isprint(int nbr);
size_t	ft_strlen(const char *str);
void	*ft_memset(void *str, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, const char *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s1, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
char	*get_next_line(int fd);
int		ft_printf(const char *s, ...);
typedef struct s_list
{
	int				content;
	struct s_list	*next;
}					t_list;

typedef struct s_data {
	char			**cmds;
	char			**files;
	char			*dir;
	int				std[2];
	struct s_data	*next;
}				t_data;

t_list	*ft_lstnew(int content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_data *lst);
t_data	*ft_lstlast(t_data *lst);
void	ft_lstadd_back(t_data **lst, t_data *new);
void	ft_delone(t_data **lst);
void	ft_lstclear(t_data **lst);
int		ft_printf(const char *s, ...);
void	ft_putchar_p(char c, int *print);
void	ft_putstr_p(char *s, int *print);
void	ft_aux_putnbr_p(int n, int *print);
void	ft_putnbr_p(int n, int *print);
void	ft_unsigned_putnbr_p(unsigned int n, int *print);
void	ft_hex(unsigned int n, int *print, char c);
void	ft_print_hex(unsigned int n, int *print, char c);
void	ft_address(unsigned long int n, int *print);
char	**ft_free(char **result);
t_data	*freecmdslst(char **result);

#endif
