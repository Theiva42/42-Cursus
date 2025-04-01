/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thkumara <thkumara@student.42singapor>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 21:58:45 by thkumara          #+#    #+#             */
/*   Updated: 2025/03/30 21:58:45 by thkumara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_strcmp(char *str1, char *str2)
{
    while (*str1 && (*str1 == *str2))
    {
        str1++;
        str2++;
    }
    return *(unsigned char *)str1 - *(unsigned char *)str2;
}

size_t	ft_strcpy(char *dst, const char *src)
{
	size_t		src_len;
	const char	*s;

	src_len = 0;
	s = src;
	while (*s++)
		src_len++;
	while (*src != '\0')
	{
		*dst++ = *src++;
		size--;
	}
	*dst = '\0';
	return (src_len);
}

size_t	ft_strcat(char *dst, const char *src)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	i = 0;
	while (src[i] != '\0')
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

int    ft_unsetenv(char *var)
{
    int i;
    int j;
    size_t  len;

    len = ft_strlen(var);
    i = 0;

    while (environ[i])
    {
        if (ft_strncmp(environ[i], var, len) == 0 && environ[i][len] == '=')
        {
            j = i;
            while(environ[j])
            {
                environ[j] = environ[j +1];
                j++;
            }
            return (1);
        }
        i++;
    }
    return (0);
}

void    handle_env()
{
    int i;

    i = 0;
    while (environ[i])
    {
        printf("%s\n", environ[i]);
        i++;
    }
}
void    handle_export(char  *arg)
{
    char	**value;
    char    **key;
    char    *existing_value;
    if (!arg)
		{
			write(2, "export: Argument missing\n", 26);
			return ;
		}
        key = ft_split(arg, '=');
		value = ft_split(NULL, " ");
		if (!key || !value)
        {
            printf ("export: invalid format, use KEY=VALUE\n");
			perror("export");
			return ;
        }
        existing_value = getenv(key);
        if (existing_value)
			printf("Updating existing variable: %s=%s\n", key, existing_value);		else
		else
			printf ("Creating new variable: %s=%s\n", key, value);
        handle_newenv(key, value);
        return ;
    }

    void    handle_newenv(char *key, char *value)
    {
        int len;
        char    *env_entry;
        int i;

        len = ft_strlen(key) + ft_strlen(value) + 2;
        env_entry = malloc (len);
        if (!env_entry)
        {
            perror("malloc failed");
            return;
        }
        ft_strcpy(env_entry, key);
        ft_strcat(env_entry, '=');
        ft_strcat(env_entry, value);
        i = 0;
        while (environ[i])
            i++;
        environ[i] = env_entry;
        environ[i + 1] = NULL;
    }

    void    handle_unset(char   *var)
    {
        if (!var)
        {
            write(STDERR_FILENO, "unset: Argument missing\n", 24);
            return ;
        }
        ft_unsetenv(var);
    }

    void    handle_echo(char    *argv)
    {
        int i;
        int append;
        char *outfile;
        int fd = STDOUT_FILENO;

        i = 1;
        append = 0;
        outfile = NULL;
        while (argv[i])
        {
            if (ft_strcmp(argv[i], '>') == 0 || ft_strcmp(argv[i], ">>") == 0)
            {
                append = (ft_strcmp(argv[i], ">>") == 0);
                outfile = argv[i + 1];
                argv[i] = NULL;
                break;
            }
            i++;
        }
        if (outfile)
    {
        fd = open(outfile, O_WRONLY | O_CREAT | (append ? O_APPEND : O_TRUNC), 0644);
        if (fd == -1)
        {
            perror("Error opening file");
            return;
        }
        dup2(fd, STDOUT_FILENO); // Redirect stdout to the file
    }

    // Print remaining arguments
    while (cmd->argv[i])
		{
			printf("%s", cmd->argv[i]);
			if(cmd->argv[i + 1])
				printf(" ");
			i++;
		}
		printf ("\n");

    // Restore stdout and close file
    if (fd != STDOUT_FILENO)
    {
        close(fd);
        dup2(STDOUT_FILENO, fd);
    }
}