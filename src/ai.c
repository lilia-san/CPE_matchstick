/*
** EPITECH PROJECT, 2020
** my ai
** File description:
** ai play
*/

#include "../include/matchstick.h"

void ai_movement(t_smart *smart)
{
    my_putstr("AI removed ");
    my_putnbr(smart->match_ai);
    my_putstr(" match(es) from line ");
    my_putnbr(smart->line_ai);
    my_putchar('\n');
}

t_smart *initialisation(t_smart *smart, int line, int match)
{
    time_t clock;
    srandom((unsigned) time(&clock));
    smart->line_ai = (random()%(line - 1 + 1)) + 1;
    smart->match_ai = (random()%(match - 1 + 1)) + 1;
    return (smart);
}

t_box *line_and_match_ai(t_smart *smart, t_box *box, int line, int match)
{
    int j = (2 * line);
    while (smart->line_ai > line || smart->line_ai <= 0 ||
        check_empty_line(box->tab[smart->line_ai]) != 84)
        smart->line_ai = (random()%(line - 1 + 1)) + 1;
    while (count_pip(box->tab[smart->line_ai], line) < smart->match_ai ||
        smart->match_ai > match)
        smart->match_ai = (random()%(match - 1 + 1)) + 1;
        if (count_pip(box->tab[smart->line_ai], line) >= smart->match_ai) {
        for (int x = smart->match_ai; x > 0; x--) {
            while (box->tab[smart->line_ai][j - 1] != '|')
                j--;
            if (box->tab[smart->line_ai][j - 1] == '|') {
                box->tab[smart->line_ai][j - 1] = ' ';
                j--;
            }
        }
    }
    ai_movement(smart);
    return (box);
}
