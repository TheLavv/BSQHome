/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_data.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteressa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 17:52:41 by mteressa          #+#    #+#             */
/*   Updated: 2020/08/31 22:32:11 by mteressa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_DATA_H
# define T_DATA_H

typedef struct	s_data
{
	int			line;
	char		empty;
	char		obst;
	char		full;
	char		**map;
}				t_data;
#endif
