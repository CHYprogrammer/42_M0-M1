/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heychong <heychong@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:18:08 by heychong          #+#    #+#             */
/*   Updated: 2025/12/17 17:12:50 by heychong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*get_line(char *stash, int nlindex);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup_start(char *s, int start);
int		ft_strlen(char *str);
int		linelen(char *str);

#endif
