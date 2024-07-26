static char	*get_buff(int fd, char *line_ptr)
{
	ssize_t	readresult;
	char	*buff;
	char	*temp;

	readresult = 1;
	temp = NULL;
	buff = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	while (readresult > 0)
	{
		readresult = read (fd, buff, BUFFER_SIZE);
		if (readresult == -1)
		{
			free (buff);
			return (NULL);
		}
		if (readresult == 0)
			break ;
		buff[readresult] = '\0';
		temp = ft_strjoin(temp, buff);
		if (ft_strchr(temp, '\n'))
			break ;
	}
	if (temp && line_ptr)
		temp = ft_strjoin1(line_ptr, temp);
	if (!temp && line_ptr)
		temp = line_ptr;
	free (buff);
	return (temp);
}