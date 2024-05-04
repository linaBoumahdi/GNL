/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboumahd <lboumahd@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 14:21:25 by lboumahd          #+#    #+#             */
/*   Updated: 2024/05/04 18:11:38 by lboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int len_new_line (char *s)
{
	int i;

	i = 0;
	while (s && s[i] != '\n')
		i++;
	return(i);
}

char *ft_strjoin (char *s1, char *s2, int cursor)
{
	char *res;
	int i;
	int j;
	int size;

	i = 0;
	j = 0;

	size = ft_strlen(s1) + ft_strlen(s2);
	if(s1)
		free(s1);
	res = malloc(size + 1);
	if(!res)
		return NULL; 
	while(s1[j])
			res[i++] = s1[j++];
	j = 0;
	while(s2[j])
		res[i++] = s2[j++];
	res[i] = '\0';
	return(res);
}
void new_line_reset(char **s1, char *s2)
{
	free(*s1);
	*s1 = s2;
}