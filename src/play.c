/*
** EPITECH PROJECT, 2019
** play
** File description:
** play
*/

#include "../include/matchstick.h"

int player_instruction(t_box *box, int line, int match)
{
    int value = 0, error = 0;
    my_putstr("\nYour turn:\n");
    value = line_of_player(box, line);
    if (value == 0)
        error = match_of_player(box, match, line);
    if (count_pip(box->tab[box->line_p], line) >= box->match_p &&
        check_empty_line(box->tab[box->line_p]) == 84 && error == 0) {
        my_putstr("Player removed ");
        my_putnbr(box->match_p);
        my_putstr(" match(es) from line ");
        my_putnbr(box->line_p);
        my_putstr("\n");
    }
    return ((value == 84 || error == 84) ? 84 : 0);
}

int count_pip(char *str, int line)
{
    int count = 0;
    int i = 0;
    for (; str[i] != '|' && str[i] != '\n' && str[i] != '\0'; i++);
    while (str[i] == '|') {
        count  = count + 1;
        i++;
    }
    return (count);
}

int check_empty_line(char *str)
{
    for (int i = 0; str[i] != '\n' && str[i] != '\0'; i++) {
        if (str[i] == '|')
            return (84);
    }
    return (0);
}

int remover_of_match(t_box *box, int line, int match)
{
    int value = 0, error = 0, j = (2 * line);
    while (count_pip(box->tab[box->line_p], line) < box->match_p ||
    check_empty_line(box->tab[box->line_p]) != 84) {
        my_putstr("Error: not enough matches on this line\n");
        value = line_of_player(box, line);
        if (value == 0)
            error = match_of_player(box, match, line);
        else
            return (84);
    }
    if (count_pip(box->tab[box->line_p], line) >= box->match_p) {
        for (int x = box->match_p; x > 0; x--) {
            for (; box->tab[box->line_p][j - 1] != '|'; j--);
            if (box->tab[box->line_p][j - 1] == '|') {
                box->tab[box->line_p][j - 1] = ' ';
                j--;
            }
        }
    }
    return ((value == 84 || error == 84) ? 84 : 0);
}
