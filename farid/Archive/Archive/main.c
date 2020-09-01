/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteressa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 14:05:23 by mteressa          #+#    #+#             */
/*   Updated: 2020/09/01 21:09:41 by mteressa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> // DELETE

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "t_data.h"
#include "parsing_file.h"

int main(int argc, char ** argv)
{	
	t_data *fdata;
	char buf[1];
	int counter;
	
	counter = 1;
	fdata = (t_data*)malloc(sizeof(t_data) * (argc - 1));
	if (argc == 1)
		while (read(0, buf, 1));
	else
		while(counter < argc)
		{
			*(fdata + (counter - 1)) = parsing_data(*(argv + counter));
			counter++;
		}
	return (0);
}
