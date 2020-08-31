#include "headers.h"

int		len(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

long long	**init_arr(t_data fdata, int s)
{
	long long	**arr;
	int		i;
	int		j;

	j = 0;
	i = 0;
	arr = (long long **)malloc(sizeof(long long *) * fdata.line);
	while (i < fdata.line)
		arr[i++] = (long long *)malloc(sizeof(long long) * s);
	i = -1;
	while (++i < fdata.line)
	{
		j = -1;
		while (++j < s)
		{
			if (fdata.map[i][j] == fdata.obst)
				arr[i][j] = 0;
			else if (!i || !j)
				arr[i][j] = 1;
			else
				arr[i][j] = -1;
		}
	}
	return (arr);
}

long long	find_min(long long a, long long b, long long c)
{
	if (a <= b && a <= c)
		return (a);
	if (b <= a && b <= c)
		return (b);
	if (c <= a && c <= b)
		return (c);
	return (a);
}

void		process_arr(long long **arr, int size, t_data fdata)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (++i < fdata.line)
	{
		j = 0;
		while (++j < size)
		{
			if (arr[i][j] != 0)
				arr[i][j] = find_min(arr[i][j - 1], arr[i - 1][j - 1], arr[i - 1][j]) + 1;
		}
	}
}

void		find_max(long long **arr, long long *max, int size, t_data fdata)
{
	int i;
	int j;

	i = -1;
	j = -1;
	while (++i < fdata.line)
	{
		j = -1;
		while (++j < size)
		{
			if (arr[i][j] > max[0])
			{
				max[0] = arr[i][j];
				max[1] = i;
				max[2] = j;
			}
		}
	}
}

void		fill_map(t_data fdata, long long *max)
{
	long long i;
	long long j;

	i = max[1] - max[0] + 1;
	j = max[2] - max[0] + 1;
	while (i < max[1] + 1)
	{
		j = max[2] - max[0] + 1;
		while (j < max[2] + 1)
		{

			fdata.map[i][j] = fdata.full;
			j++;
		}
		i++;
	}
}

void		print_map(t_data fdata, int size)
{
	int i;
	int j;

	i = -1;
	j = -1;
	while (++i < fdata.line)
	{
		j = -1;
		while (++j < size)
		{
			write(1, &(fdata.map[i][j]), 1);
		}
		write(1, "\n", 1);
	}
}

long long	*init_max()
{
	long long *max;

	max = (long long *)malloc(sizeof(long long) * 3);
	max[0] = 0;
	max[1] = 0;
	max[2] = 0;
	return (max);
}

void		print_arr(long long **arr, int size, t_data fdata)
{
	int i;
	int j;

	i = -1;
	j = -1;
	while (++i < fdata.line)
	{
		j = -1;
		while (++j < size)
		{
			printf("%lld ", arr[i][j]);
		}
		printf("\n");
	}
}

int		bsq(t_data fdata)
{
	long long	**arr;
	int		size;
	long long	*max;

	max = init_max();
	size = len(fdata.map[0]);
	arr = init_arr(fdata, size);
	//print_arr(arr, size, fdata);
	process_arr(arr, size, fdata);
	//printf("\n\n");
	//print_arr(arr, size, fdata);
	find_max(arr, max, size, fdata);
	//printf("max=%lld i=%lld j=%lld", max[0], max[1], max[2]);
	if (max[0] != 0)
	{
		//printf("i=%lld j=%lld map=%c\n", max[1] - max[0] + 1, max[2] - max[0] + 1, fdata.map[max[1] - max[0] + 1][max[2] - max[0] + 1] = 'x');
		fill_map(fdata, max);
		print_map(fdata, size);
		free(max);
		free(arr);
		return (1);
	}
	return (0);
}
