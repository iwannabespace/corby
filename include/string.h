#ifndef _string_h_
#define _string_h_

int	ft_strlen(char *str);
int	ft_strcmp(char *s1, char *s2);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strlcpy(char *dest, char *src, unsigned int n);
char	**ft_split(char *str);

//aux
int	_count_words(char *str);
int	_isspace(char c);
int	_is_alpha(char c);
char	*_first_space(char *str);

#endif
