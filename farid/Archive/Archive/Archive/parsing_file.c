/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteressa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 20:59:38 by mteressa          #+#    #+#             */
/*   Updated: 2020/09/01 21:32:33 by mteressa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "t_data.h"
#include "parsing_file.h"
#include <stdio.h>

char 	*read_str(char *argv) //Создание строки даты
{
	int counter_1;
	char *buf_str;
	char buf;
	int fd;

	counter_1 = 0;
	fd = open(argv, O_RDONLY);
	while (read(fd, &buf, 1) > 0)
	{
		if (buf != '\n')
			counter_1++;
		else
			break;
	}
	buf_str = (char*)malloc(sizeof(char) * (counter_1 + 1));
	close(fd);
	fd = open(argv, O_RDONLY);
	counter_1 = 0;
	while (read(fd, &buf, 1) > 0)
	{
		if (buf != '\n')
		{
			buf_str[counter_1] = buf;
			counter_1++;
		}
		else
			break;
	}
	close(fd);
	buf_str[counter_1] = '\0';
	return (buf_str);
}

int		check_data(char *buf_str, int discharge) // проверка даты
{
	int counter_2;

	counter_2 = discharge;
	while (*(buf_str + counter_2) != '\0')	
			counter_2++;
	if (counter_2 - discharge == 3)
		return (1);
	return (0);
}

int count_line(char *argv)
{
	int		fd;
	char	buf;
	int		counter;

	counter = 0;
	fd = 0;
	fd = open(argv, O_RDONLY);
	while(read(fd, &buf, 1) > 0)
	{
		if(buf == '\n')
			counter++;
	}
	return (counter - 1);
}

char	**create_data_arr(char *argv) // создаю массив для поля map
{
	char **data_arr;
	int fd;
	int counter_1;
  	int counter_2;
	int buf[1];

	counter_1 = 0;
	counter_2 = 0;
	data_arr =(char **)malloc(sizeof(char *) * count_line(argv));
	fd = open(argv, O_RDONLY);
	while (read(fd, buf, 1) > 0)
	{
		if (buf[0] != '\n')
			counter_1++;
		else
		{
			while(read(fd, buf, 1) > 0)
			{
				if(buf[0] != '\n')
					counter_2++;
                		else
					break;
			}
		}
	}
    close(fd);
    fd = open(argv, O_RDONLY);
    while (read(fd, buf, 1) > 0)
    {
        if (buf[0] == '\n')
            break;
    }
    counter_1 = -1;
    while (++counter_1 < count_line(argv))
    {
	    data_arr[counter_1] = (char *)malloc(sizeof(char) * counter_2);
    }
    counter_1 = 0;
    counter_2 = 0;
    while (read(fd, buf, 1) > 0)
    {
	    if(buf[0] != '\n')
	    {
		    data_arr[counter_1][counter_2] = buf[0];
		    counter_2++;
	    }
	    else
	    {
		    counter_1++;
		    counter_2 = 0;
	    }
    }
    return (data_arr);
}

t_data 	create_data(char *buf_str, int discharge, char *argv) // тут структуру бахаю даты
{
	t_data buf_data;

	buf_data.line = count_line(argv);
	buf_data.empty = buf_str[discharge];
	buf_data.obst = buf_str[discharge + 1];
	buf_data.full = buf_str[discharge + 2];
	buf_data.map = create_data_arr(argv);
	return (buf_data);
}

int 	count_discharge(char *argv) //Подсчет разряда для разделения даты  (нужна для проверки на корректность кода)
{
	int	counter_1;
	int	discharge;
	int	fd;
	char	buf;

	fd = open(argv, O_RDONLY);
	counter_1 = 0;
	discharge = 0;
	while (read(fd, &buf, 1) > 0)
	{
		if (buf == '\n')
			counter_1++;
	}
	while (counter_1 != 0)
	{
		counter_1 = counter_1 / 10;
		discharge++;
	}
	return (discharge);
}

void	print_data(t_data buf_data)
{
	printf("%d%c%c%c\n", buf_data.line, buf_data.empty, buf_data.obst, buf_data.full);
	int i = 0;
	int j = 0;

	while (i < buf_data.line)
	{
		j = 0;
		while (buf_data.map[i][j])
		{
			printf("%c", buf_data.map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

t_data	parsing_data(char *argv)
{
	t_data	buf_data;
	char	*buf_str;
	int	discharge;

	buf_data.line = 0;
	buf_data.empty = 0;
	buf_data.obst = 0;
	buf_data.full = 0;
	buf_data.map = 0;
	buf_str = read_str(argv);
	discharge = count_discharge(argv);
	if (check_data(buf_str, discharge) == 1)
	{
		buf_data = create_data(buf_str, discharge, argv);
		print_data(buf_data);
	}
	else
		write(1, "map error\n", 10);
	return (buf_data);
}
