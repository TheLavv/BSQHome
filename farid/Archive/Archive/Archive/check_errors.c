#include "stdio.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "parsing_file.h"
#include "t_data.h"

int file_is_open(char *argv) // Открытие файла
{
    if (open(argv, O_RDONLY) < 0)
    {
        write(1, "FILE ERROR\n", 11);
        return (0);
    }
    return (1);
}

int	count_len_str(int fd)
{
	int len;
	char buf;

	len = 0;
	while (read(fd, &buf, 1))
        {
            if (buf == '\n')
                break;
        }
        while (read(fd, &buf, 1))
        {
                if (buf == '\n')
            	    break;
                len++;
        }
	printf("%d\n\n", len);
	return (len);
}	

int count_length(char *argv) //Корректность длин строк и проверка на \n. Правильно ли я понял что мы должны с первой строкой сравнивать ?
{
    int fd;
    int counter_1;
    int	len;
    char buf;
    
    fd = open(argv, O_RDONLY);
    len = count_len_str(fd);
    counter_1 = 0;
    while (read(fd, &buf,1))
    {

        if (buf != '\n')
        {
		counter_1++;
	}
	else
	{
		if (counter_1 != len)
			return (0);
		counter_1 = 0;
	}
    }
    return(1);
}

int check_data_file (char *argv) //убрать из парсинга хз
{
    char *buf_str;
    int discharge;
    buf_str = read_str(argv);
    discharge = count_discharge(argv);
    if (check_data(buf_str, discharge) == 1)
        return (1);
    else
        write(1, "MAP ERROR\n", 10);
    return (0);
}

int check_symbol(char *argv)
{
    char *buf_str;
    int discharge;

    buf_str = read_str(argv);
    discharge = count_discharge(argv);
    if (buf_str[discharge] == buf_str[discharge + 1] || buf_str[discharge + 1] == buf_str[discharge + 2] || buf_str[discharge + 2] == buf_str[discharge])
    {
	    return (0);
	    write(1, "MAP ERROR\n", 10);
    }
    return (1);
}

int check_printable(char *argv)
{
    char *buf_str;
    int discharge;

    buf_str = read_str(argv);
    discharge = count_discharge(argv); 
    while(*(buf_str + discharge) != '\0')
    {
        if(!(buf_str[discharge] >= 32 && buf_str[discharge] <= 126))
        {
            write(1, "MAP ERROR", 1);
            return (0);
        }
        discharge++;
    }
    return (1);
}

/*int check_end_file(char *argv) // Это вообще можно реализовать ?
{(void*)argv;
    return (1);
}*/

int check_error(char *argv)
{
    if (file_is_open(argv) == 0)
        return (0);
    if (count_length(argv) == 0)
    {
        write(1, "MAP ERROR\n", 10);
        return (0);
    }
    else if (check_symbol(argv) == 0)
        return (0);
    /*else if (check_printable(argv) == 0)
        return (0);*/
    return (1);
}
