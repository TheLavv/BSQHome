#ifndef HEADERS_H
# define HEADERS_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct	s_data
{
	int	line;
	char	empty;
	char	obst;
	char	full;
	char	**map;
}		t_data;

int		bsq(t_data fdata);

#endif
