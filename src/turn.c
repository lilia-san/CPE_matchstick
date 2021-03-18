/*
** EPITECH PROJECT, 2020
** matchstick
** File description:
** projet
*/

#include "../include/matchstick.h"

int check_if_empty(t_box *box)
{
    for (int i = 0; box->tab[i] != NULL; i++) {
        if (check_empty_line(box->tab[i]) == 84)
            return (84);
    }
    return (0);
}

void ai_turn(t_smart *smart, t_box *box, int line, int match)
{
    my_putstr("\nAI's turn...\n");
    initialisation(smart, line, match);
    line_and_match_ai(smart, box, line, match);
    display_box_match(box);
}

t_smart loop_game(t_smart *smart, t_box *box, int line, int match)
{
    int value = 0, error = 0;
    smart->winner = 0;
    while (check_if_empty(box) == 84) {
        smart->value = player_instruction(box, line, match);
        if (smart->value == 0) {
            smart->error = remover_of_match(box, line, match);
            if (smart->error == 0)
                display_box_match(box);
        }
        if (check_if_empty(box) != 84) {
            my_putstr("You lost, too bad...\n");
            smart->winner = 2;
            return (*smart);
        }
        if (smart->value == 84 || smart->error == 84)
            return (*smart);
        ai_turn(smart, box, line, match);
        if (check_if_empty(box) != 84) {
            my_putstr("I lost... snif... but I'll get you next time!!\n");
            smart->winner = 1;
            return (*smart);
        }
    }
    return (*smart);
}
