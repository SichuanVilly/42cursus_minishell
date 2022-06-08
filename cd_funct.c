/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_funct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 20:57:52 by pvillena          #+#    #+#             */
/*   Updated: 2022/05/25 17:44:36 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*check_dir(char **args, char *path)
{
	char	*new_dir;
	char	*aux;
	int		fd;

	if (args[1] && args[1][0] == '/')
		return (args[1]);
	path = ft_strjoin(path, "/");
	new_dir = ft_strjoin(path, args[1]);
	if (new_dir[ft_strlen(new_dir) - 1] == '/')
	{
		aux = ft_substr(new_dir, 0, ft_strlen(new_dir) - 1);
		free(new_dir);
		new_dir = aux;
	}
	free(path);
	fd = open(new_dir, O_DIRECTORY | O_RDONLY);
	if (fd > 0)
	{
		close(fd);
		return (new_dir);
	}
	return (NULL);
}

void	replace_pwd_oldpwd(char *new_dir, char *path, char **env)
{
	int		i;
	char	*aux;

	i = -1;
	while (env[++i])
	{
		if (ft_strncmp(env[i], "PWD=", 4) == 0)
		{
			aux = env[i];
			env[i] = ft_strjoin("PWD=", new_dir);
			free(aux);
		}
	}
	chdir(new_dir);
	i = -1;
	while (env[++i])
	{
		if (ft_strncmp(env[i], "OLDPWD=", 4) == 0)
		{
			aux = env[i];
			env[i] = ft_strjoin("OLDPWD=", path);
			free(aux);
		}
	}
}

char	*back_one_dir(char *path)
{
	int		len;
	char	*new_dir;

	if (ft_strncmp(path, "/", 5) == 0)
		return (path);
	len = ft_strlen(path);
	while (path[len] != '/')
		len--;
	new_dir = ft_substr(path, 0, len);
	return (new_dir);
}

char	*get_home(char **env)
{
	char	*new_dir;

	while (*env)
	{
		if (ft_strncmp(*env, "HOME=", 5) == 0)
		{
			new_dir = ft_substr(*env, 5, UINT_MAX);
			return (new_dir);
		}
		env++;
	}
	ft_putstr_fd("minishell: cd : HOME not set\n", 1);
	return (NULL);
}

char	**ft_cd(char **args, char **env)
{
	char	*path;
	char	*new_dir;

	if (!env)
		return (NULL);
	path = get_pwd();
	if (!args[1] || ft_strncmp(args[1], "~", 5) == 0)
		new_dir = get_home(env);
	else if (ft_strncmp(args[1], "..", 5) == 0)
		new_dir = back_one_dir(path);
	else if (ft_strncmp(args[1], "-", 5) == 0)
		new_dir = get_oldpwd(env);
	else
		new_dir = check_dir(args, path);
	if (new_dir)
		replace_pwd_oldpwd(new_dir, path, env);
	free(path);
	free(new_dir);
	return (env);
}
