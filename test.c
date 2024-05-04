char	*get_next_line(int fd)
{
	int			check;
	static char	remains[BUFFER_SIZE + 1];
	char		*res;

	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE < 1)
		return (NULL);
	check = -1;
	res = join_strdup(remains, &check);
	if (!res)
		return (NULL);
	ft_strlcpy(remains, &remains[check + 1], BUFFER_SIZE + 1);
	res = add_to_line(res, remains, &check, fd);
	if (!res || res[0] == '\0')
	{
		free(res);
		return (NULL);
	}
	return (res);
}