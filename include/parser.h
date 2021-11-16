#ifndef _parser_h_
# define _parser_h_

# include "types.h"

CMD	*ft_parse(char *fname);

//aux
char	*_readf(char *fname, int size);
int	_cmd_count(char **buf);
int	_define_variable(CMD *cmd, char **buf, int size);

#endif
