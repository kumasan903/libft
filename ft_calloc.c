/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skawanis <skawanis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:51:31 by skawanis          #+#    #+#             */
/*   Updated: 2023/01/24 08:40:34 by skawanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_calloc(size_t count, size_t size) {
  size_t sum;
  void *ptr;
  size_t bytes;

  if (count == 0 || size == 0) {
    count = 1;
    size = 1;
  }
  bytes = count * size;
  if (bytes / size != count)
    return (NULL);
  sum = count * size;
  ptr = malloc(sum);
  if (ptr == NULL)
    return (NULL);
  ft_bzero(ptr, sum);
  return (ptr);
}
