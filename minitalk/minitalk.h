/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evmouka <evmouka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:39:36 by evmouka           #+#    #+#             */
/*   Updated: 2024/06/17 18:13:12 by evmouka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <stdio.h>
# include <sched.h>

void	handle_signal(int signal);
// void	send_signal(int pid, char *message);
void	send_signal(int pid, unsigned char character);

#endif
