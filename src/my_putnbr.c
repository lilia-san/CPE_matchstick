/*
** EPITECH PROJECT, 2019
** my_put_nbr
** File description:
** put number
*/

#include "../include/matchstick.h"

int my_putnbr(int n)
{
    if (n >= 0 && n <= 9)
        my_putchar(n + '0');
    else if (n < 0) {
        my_putchar('-');
        n *= (-1);
        my_putnbr(n);
    } else {
        my_putnbr(n/ 10);
        my_putnbr(n % 10);
        }
    return (0);
}
