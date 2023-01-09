/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mylib.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skawanis <skawanis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 05:28:52 by skawanis          #+#    #+#             */
/*   Updated: 2023/01/09 05:28:54 by skawanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> //for write
#include <stdlib.h> //for malloc

size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dest, const void *src, size_t n);
size_t	ft_strlcpy(char *dest, const char *src, size_t size); 
