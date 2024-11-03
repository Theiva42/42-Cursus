/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thkumara <thkumara@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 17:06:51 by thkumara          #+#    #+#             */
/*   Updated: 2024/11/03 14:06:22 by thkumara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <stdarg.h>
# include <stdbool.h>
# include <limits.h>

void	send_bits(pid_t pid, char c);
void	signal_handler(int sig);
void	setup_signal_handlers(void);
void	args_check(int argc, char **argv);
void	send_msg(pid_t server_pid, char *message);
int		ft_isdigit(int i);
int		ft_strlen(const char *str);
void	print_error_and_exit(char *error_msg);
int		ft_atoi(const char *str);
void	process_incoming_signal(int signal_number,
			siginfo_t *signal_info, void *context);
int		ft_putchar_fd(char c, int fd);
int		ft_putnbr_base(unsigned long long nb, const char *base);
int		ft_putchar(char c);
int		ft_printf(const char *format, ...);
int		ft_handle_char(va_list ap);
int		ft_handle_int(va_list ap);
int		ft_handle_hexlower(va_list ap);
int		ft_handle_hexupper(va_list ap);
int		ft_handle_percent(void);
int		ft_handle_pointer(va_list ap);
int		ft_handle_string(va_list ap);
int		ft_handle_unsigned(va_list ap);

#endif
