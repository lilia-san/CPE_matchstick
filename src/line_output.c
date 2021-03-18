/*
** EPITECH PROJECT, 2019
** line play
** File description:
** line play
*/

#include "../include/matchstick.h"

int line_of_player(t_box *box, int line)
{
    int value = 0;
    box->line_p = 0;
    char *buffer = NULL;
    size_t len = 0, nread = 0;
    my_putstr("Line: ");
    if ((nread = getline(&buffer, &len, stdin)) != -1) {
        if (buffer[0] == 0) {
            return (84);
        }
        else {
            box->line_p = my_getnbr(buffer);
            if (bad_stuff(buffer) == 84 || buffer[0] == '\n') {
                my_putstr("Error: invalid input (positive number expected)\n");
                value = line_of_player(box, line);
                if (value == 84)
                    return (84);
            }
        }
    } else
        return (84);
    check_line(box, line);
    return (0);
}

int check_line(t_box *box, int line)
{
    int value = 0;
    if (box->line_p > line || box->line_p == 0) {
        my_putstr("Error: this line is out of range\n");
        value = line_of_player(box, line);
    }
    if (box->line_p < 0) {
        my_putstr("Error: invalid input (positive number expected)\n");
        value = line_of_player(box, line);
    }
    return (value);
}

int bad_stuff(char *str)
{
    for (int i = 0; str[i] != '\0' && str[i] != '\n'; i++) {
        if (str[i] < '0' || str[i] > '9')
            return (84);
    }
    return (0);
}
