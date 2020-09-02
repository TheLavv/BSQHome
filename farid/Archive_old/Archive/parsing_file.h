/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_file.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteressa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 16:13:41 by mteressa          #+#    #+#             */
/*   Updated: 2020/09/01 21:22:31 by mteressa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_FILE_H
# define PARSING_FILE_H

t_data	parsing_data(char *argv);
int 	count_discharge(char *argv);
t_data 	create_data(char *buf_str, int discharge, char *argv);
int		check_data(char *buf_str, int discharge);
char 	*read_str(char *argv);
#endif
