/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 17:46:04 by shong             #+#    #+#             */
/*   Updated: 2021/01/04 17:49:23 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char *a = malloc(1);
	char *b = "abc";
	printf("%s \n", memmove(a,b,3));
	printf("%s \n", memmove(a,b,100000));
	free(a);
}
