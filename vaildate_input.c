/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vaildate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhis@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:33:14 by halmuhis          #+#    #+#             */
/*   Updated: 2025/02/08 15:56:45 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static int is_valid_number(char *str)
{
    int i;

    i = 0;
    if (str[i] == '-' || str[i] == '+')
        i++;
    if (!str[i])
        return (0);
    while (str[i])
    {
        if (!ft_isdigit(str[i]))
            return (0);
        i++;
    }
    return (1);
}

static int check_int_limits(char *str)
{
    size_t len;

    len = ft_strlen(str);
    if (len > 11)
        return (0);
    if (len == 10 && str[0] != '-' && str[0] != '+')
    {
        if (ft_strncmp(str, "2147483647", 10) > 0)
            return (0);
    }
    else if (len == 11 && str[0] == '-')
    {
        if (ft_strncmp(str, "-2147483648", 11) > 0)
            return (0);
    }
    return (1);
}

static void free_split(char **str)
{
    int i;

    i = 0;
    while (str[i])
    {
        free(str[i]);
        i++;
    }
    free(str);
}

void validate_input(t_stack *a, char *argv)
{
    char **str;
    int i;

    str = ft_split(argv, ' ');
    if (!str)
        exit(EXIT_FAILURE);
    i = -1;
    while (str[++i])
    {
        if (!is_valid_number(str[i]) || !check_int_limits(str[i]))
        {
            free_split(str);
            write(1, "\nerror\n", 7);
            exit(EXIT_FAILURE);
        }
        // check_dup(&arr, str[i]);
        push(a, ft_atoi(str[i]));
    }
    free_split(str);
}

// static void check_dup(char **arr, char *num)
// {
//     int i;
//     int check;
//     static int index;
    
//     i = 0;
//     check = ft_atoi(num);
//     if (!arr)
//         exit(1);
//     while (i < index)
//     {
//         if (arr[i] == check)
//         {
//             free(arr);
//         }
//         i++;
//     }
//     arr[index] = check;
//     index++;
//     free(arr);
// }