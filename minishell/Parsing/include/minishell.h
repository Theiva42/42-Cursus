/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thkumara <thkumara@student.42singapor>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 14:58:54 by sbin-ham          #+#    #+#             */
/*   Updated: 2025/04/01 13:40:53 by thkumara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include "lexer.h"
# include "parser.h"
# include <stdio.h>					// for printf
# include <stdlib.h>				// for malloc, free, exit
# include <unistd.h>				// for fork, execve, pipe
# include <sys/wait.h>				// for wait
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>

extern char	**environ;

int is_builtin(char *cmd);
int execute_builtin(t_command *cmd);
void execute_commands(t_command *cmd_head, char **envp);
int ft_strcmp(char *str1, char *str2);
int ft_unsetenv(char *var);
void    print_env(void);
void    handle_env();
void    handle_export(char  *arg);
void    handle_newenv(char *key, char *value);
void    handle_unset(char   *var);
void    handle_echo(char    *argv);
size_t	ft_strcpy(char *dst, const char *src);

#endif
