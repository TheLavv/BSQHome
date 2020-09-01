#include "headers.h"

int	main()
{
	t_data fdata;
	int size = 6;
	char *temp_map[] = {"....0...", ".0....0.", ".....0..", "........", ".0...0..", "........"};
	fdata.line = size;
	fdata.empty = '.';
	fdata.obst = '0';
	fdata.full = 'x';
	fdata.map = (char **)malloc(sizeof(char *) * size);
	int i = 0;
	int j = 0;
	while (i < size)
	{
		fdata.map[i] = (char *)malloc(sizeof(char) * 9);
		i++;
	}
	i = 0;
	while (i < size)
	{
		j = 0;
		while (temp_map[i][j])
		{
			fdata.map[i][j] = temp_map[i][j];
			j++;	
		}
		fdata.map[i][j] = temp_map[i][j];
		i++;
	}
	bsq(fdata);
	return (0);
}
