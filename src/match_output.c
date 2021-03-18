/*
** EPITECH PROJECT, 2019
** play
** File description:
** play
*/

#include "../include/matchstick.h"

int match_of_player(t_box *box, int match, int line)
{
    int value = 0, error = 0;
    char *buffer = NULL;
    size_t len = 0, nread = 0;
    box->match_p = 0;
    my_putstr("Matches: ");
    if ((nread = getline(&buffer, &len, stdin)) != -1) {
        if (buffer[0] == 0)
            return (84);
        else {
            box->match_p = my_getnbr(buffer);
            if (bad_stuff(buffer) == 84 || buffer[0] == '\n') {
                my_putstr("Error: invalid input (positive number expected)\n");
                value = line_of_player(box, line);
                if (value == 84)
                    return (84);
                error = match_of_player(box, match, line);
                if (error == 84)
                    return (84);
            }
        }
    } else
        return (84);
    check_match(box, match, line);
    return (0);
}

void match_movement(int match)
{
    my_putstr("Error: you cannot remove more than ");
    my_putnbr(match);
    my_putstr(" matches per turn\n");
}

int check_match(t_box *box, int match, int line)
{
    int value = 0, error = 0;
    if (box->match_p > match) {
        match_movement(match);
        value = line_of_player(box, line);
        if (value == 0)
            error = match_of_player(box, match, line);
    }
    if (box->match_p == 0) {
        my_putstr("Error: you have to remove at least one match\n");
        value = line_of_player(box, line);
        if (value == 0)
            error = match_of_player(box, match, line);
    }
    if (box->match_p < 0) {
        my_putstr("Error: invalid input (positive number expected)\n");
        value = line_of_player(box, line);
        if (value == 0)
            error = match_of_player(box, match, line);
    }
    return ((value == 84 || error == 84) ? 84 : 0);
}
