/*
** EPITECH PROJECT, 2019
** main
** File description:
** main
*/

#include "../include/matchstick.h"

int main(int ac, char **av)
{
    int line = 0;
    int match = 0;
    t_box box;
    t_smart smart;
    if (ac == 3) {
        line = my_getnbr(av[1]);
        match = my_getnbr(av[2]);
        if (line <= 1 || match <= 0 || bad_stuff(av[1]) == 84 ||
            bad_stuff(av[2]) == 84)
            return (84);
        else
            smart = playing(smart, box, line, match);
    }
    else
        return (84);
    return ((smart.value == 84 || smart.error == 84) ? 0 : smart.winner);
}

t_smart playing(t_smart smart, t_box box, int line, int match)
{
    malloc_tab(&box, line);
    fill_tab(&box, line);
    display_box_match(&box);
    smart = loop_game(&smart, &box, line, match);
    return (smart);
}
