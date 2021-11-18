#ifndef _string_h_
#define _string_h_

#include "linked_list.h"

int	ft_strlen(const char *str);
int	ft_strcmp(char *s1, const char *s2);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strlcpy(char *dest, const char *src, unsigned int n);
list*	ft_split_line(const char *str);

//aux
int	_isspace(char c);
int	_is_alpha(char c);
char	*_first_space(const char *str);

#endif
