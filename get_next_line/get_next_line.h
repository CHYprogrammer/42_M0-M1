/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heychong <heychong@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:18:08 by heychong          #+#    #+#             */
/*   Updated: 2025/12/23 22:00:27 by heychong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*handle_end(char **stash_ptr, int r_bytes);
char	*ret_line(char **stash_ptr);
void	update_stash(char **stash_ptr, char *remainder);
int		find_lf(char *str);
char	*ft_strjoin_free(char *s1, char *s2);
char	*ft_strdup(const char *s);
int		ft_strlen(const char *str);
void	free_and_null(char **ptr);

#endif
