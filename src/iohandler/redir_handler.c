/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 13:24:11 by hyospark          #+#    #+#             */
/*   Updated: 2021/11/16 17:12:30 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	d_redir_cmd(t_bundle *bundle, t_token *token)
{
	int	fd_num[2];

	set_fd(token, fd_num);
	if (token->token_type == D_REDIR_OUT)
	{
		if (fd_num[0] > -1)
			dup2(fd_num[0], STDIN_FILENO);
		if (fd_num[0] < 0)
		{
			fd_num[0] = open(token->next->content, O_WRONLY | O_APPEND | O_CREAT, 0666);
			if (fd_num[0] < 0)
				print_error("redir open file error", EXIT_FAILURE);
		}
		dup2(fd_num[0], STDOUT_FILENO);
	}
	if (token->token_type == D_REDIR_IN)
	{
		
	}
}

int	redir_cmd(t_bundle *s_bundle, t_token *token)
{
	int	fd_num[2];

	set_fd(token, fd_num);
	if (token->token_type == REDIR_OUT)
	{
		if (fd_num[0] > -1)
			dup2(fd_num[0], STDIN_FILENO);
		if (fd_num[1] < 0)
		{
			fd_num[1] = open(token->next->content, O_WRONLY | O_TRUNC | O_CREAT, 0666);
			if (fd_num[1] < 0)
				print_error("redir open file error", EXIT_FAILURE);
		}
		dup2(fd_num[1], STDOUT_FILENO);
	}
	if (token->token_type == REDIR_IN)
	{
		if (fd_num[0] > -1)
			dup2(fd_num[0], STDIN_FILENO);
		if (fd_num[1] < 0)
		{
			fd_num[1] = open(token->next->content, O_RDONLY);
			if (fd_num[1] < 0)
				print_error("redir opne file error", EXIT_FAILURE);
		}
		dup2(fd_num[1], STDIN_FILENO);
	}
}

int	*set_fd(t_token *token, int	fd_num[])
{
	if (is_fdnum(token->pre->content, 0) == 1 && token->pre->back_space == 0)
		fd_num[0] = token->pre->content[0] + '0';
	else
		fd_num[0] = -1;
	if (is_fdnum(token->next->content, 1) == 2 && token->back_space == 0)
		fd_num[1] = (token->pre->content[1] + '0');
	else
		fd_num[1] = -1;
	return (fd_num);
}

int	redir_handler(t_bundle *bundle, t_token *token)
{
	int	pid;
	int status;

	pid = fork();
	if (pid < 0)
		print_error("redir fork error", EXIT_FAILURE);
	if (pid == 0)
	{
		if (token->token_type == D_REDIR_IN || token->token_type == D_REDIR_OUT)
		{
			status = d_redir_cmd(bundle, token);
		}
		else if (token->token_type == REDIR_IN || token->token_type == REDIR_OUT)
		{
			status = redir_cmd(bundle, token);
		}
		exit(status);
	}
	else
	{
		wait(&status);
		exit(status);
	}
}