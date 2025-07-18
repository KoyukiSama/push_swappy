/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/22 16:57:18 by kclaes        #+#    #+#                 */
/*   Updated: 2025/07/18 16:52:50 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdbool.h>

// (ft_ctype)
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_toint(char c);
char	ft_tochar(int c);
int		ft_isspace(int c);

// (ft_mem)
void	*ft_memset(void *s, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t n, size_t size);

// (ft_string)
size_t	ft_strlen(const char *s);
char	*ft_strlower(char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_streq(const char *s1, const char *s2, bool case_sensitive);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strdup(const char *s);
char	*ft_str_mallocpy(const char *s, size_t ln);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);

// (ft_split.c)
typedef struct s_ss
{
	char	**ss;
	size_t	ss_ln;
	size_t	*s_starts;
	size_t	*s_lens;
}	t_ss;

char	**ft_split(char const *s, char c);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

// (ft_stdlib)
int		ft_atoi(const char *nptr);
char	*ft_itoa(int n);
double	ft_atod(const char *nptr);

// (ft_files)
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

// (ft_math)
int		ft_abs(int x);
size_t	ft_next_p2(size_t nbr);

// (ft_get_next_line)
# ifdef BUFFER_SIZE
#  define BUFF_SIZE BUFFER_SIZE
# else
#  define BUFF_SIZE 42
# endif
# define OPEN_MAX 1024

// stash_strt_ptr is the malloc pointer
// stash is a modified ptr
typedef struct s_stash
{
	char	*stash;
	char	*stash_strt_ptr;
}	t_stash;

char	*get_next_line(int fd);

#endif