/*
** EPITECH PROJECT, 2019
** my_getnbr
** File description:
** return number as a string
*/

#include <unistd.h>
#include <stdio.h>

int my_getnbr(char const *str)
{
    int res = 0;
    int n = 1;
    int i = 0;
    while (str[i] != '\0' && (str[i] == '+' || str[i] == '-')) {
        if (str[i] == '-') {
            n = n * (-1);
        }
        i++;
    }
    while (str[i] >= 48 && str[i] <= 57) {
        res = (res * 10) + str[i] - 48;
        i++;
    }
    return (res * n);
}
