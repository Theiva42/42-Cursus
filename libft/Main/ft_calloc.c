/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thkumara <thkumara@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:24:32 by thkumara          #+#    #+#             */
/*   Updated: 2024/05/20 15:10:48 by thkumara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (i < n)
	{
		*(str + i) = c;
		i++;
	}
	return (s);
}

void *ft_calloc(size_t nmemb, size_t size)
{
	void	*arr;

	arr = malloc(nmemb * size);
	if (arr == NULL)
		return (NULL);
	ft_memset(arr, 0, nmemb * size);
	return (arr);

}

int main()
{
    size_t nmemb = 5;
    size_t size = sizeof(int);
    size_t	i = 0;
    //int *arr = ft_calloc(nmemb, size);
    int *arr = calloc(nmemb, size);

    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Print the elements of the array to verify that they are initialized to zero
    while (i < nmemb) 
    {
        printf("%d ", arr[i]);
	i++;
    }
    printf("\n");

    // Free the allocated memory
    free(arr);

    return 0;
}
