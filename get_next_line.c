/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboumahd <lboumahd@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 10:14:23 by lboumahd          #+#    #+#             */
/*   Updated: 2024/05/03 17:08:05 by lboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char *add_line (char *remains,char *new_line,int cursor, int fd)
{
	char buffer[BUFFER_SIZE + 1];
	int	read_check;
	int len_line;

	if (cursor == -1)
	{
		//set buff fbzero ou calloc 
		read_check = read(fd, buffer, BUFFER_SIZE);
		if (read_check == 0 || read_check == -1)
			return NULL;
		// calculate len of line + \n
		len_line = len_new_line(buffer);
		//copy chutes of buffer to remains
		ft_strlcpy (remains, &buffer[len_line], BUFFER_SIZE);
		//set new buffer 
		ft_strlcpy(buffer, buffer, len_line);
		// join buff + new_line
		new_line = ft_strjoin(new_line, buffer);// memory leak double allocation 
	}
	return(new_line);
}

char	*get_next_line (int fd)
{
	char		*new_line;
	static char	remains[BUFFER_SIZE +1];
	int			cursor;

	//error checking : 
	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX || fd >= OPEN_MAX)
		return NULL;
	cursor = -1;
	//second call : 
	//first call : 
	new_line = add_line(remains, new_line, &cursor,fd);
	return(new_line);
}


