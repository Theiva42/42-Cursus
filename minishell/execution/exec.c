/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thkumara <thkumara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 16:16:16 by thkumara          #+#    #+#             */
/*   Updated: 2025/03/29 16:21:35 by thkumara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void	execute_commands(t_command *cmd_head)
{
	int fd_in;
	int fd;
	int pipefd[2];
	pid_t	pid;

	fd_in = 0;
	while (cmd_head)
	{
		if (cmd_head->next && pipe(pipefd) == -1)
		{
			perror("pipe failed");
			exit(EXIT_FAILURE);
		}
		pid = fork();
		if (pid == -1)
		{
			perror("fork failed");
			exit(EXIT_FAILURE);
		}
		if (pid == 0)
		{
			if (cmd_head->infile)
			{
				int fd = open(cmd_head->infile, O_RDONLY);
				if (fd == -1)
				{
					perror("open infile failed");
					exit(EXIT_FAILURE);
				}
				dup2(fd, STDIN_FILENO);
				close(fd);
			}
			else if (fd_in != 0)
			{
				dup2(fd_in, STDIN_FILENO);
				close(fd_in);
			}
			if (cmd_head->outfile)
			{
				if (cmd_head->append_out)
					fd = open(cmd_head->outfile, O_WRONLY | O_CREAT | O_APPEND, 0644);
				else
					fd = open(cmd_head->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
				if (fd == -1)
				{
					perror("open outfile failed");
					exit(EXIT_FAILURE);
				}
				dup2(fd, STDOUT_FILENO);
				close(fd);
			}
			else if (cmd_head->next)
			{
				dup2(pipefd[1], STDOUT_FILENO);
				close(pipefd[1]);
				close(pipefd[0]);
			}
			execvp(cmd_head->argv[0], cmd_head->argv);
			perror("execvp failed");
			exit(EXIT_FAILURE);
		}
		if (fd_in != 0)
			close(fd_in);
		if (cmd_head->next)
		{
			close(pipefd[1]);
			fd_in = pipefd[0];
		}
		cmd_head = cmd_head->next;
	}
	while (wait(NULL) > 0);
}
