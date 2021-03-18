/*
** EPITECH PROJECT, 2019
** main
** File description:
** main
*/

#include "../include/matchstick.h"

t_box *malloc_tab(t_box *box, int line)
{
    int i = 0;
    box->tab = NULL;
    box->tab = malloc(sizeof(char *) * (line + 3));
    if (box->tab == NULL)
        return (NULL);
    for (i = 0; i < (line + 3); i++)
        box->tab[i] = malloc(sizeof(char) * ((2 * line) + 3));
    box->tab[i] = NULL;
    return (box);
}

void put_pip(t_box *box, int line, int i)
{
    int j = 0;
    int pipe = (2 * (i - 1)) + 1;
    int npip = (((2 * line) - 1) - pipe) / 2;
    for (int x = npip + 1; j < pipe; x++, j++)
        box->tab[i][x] = '|';
}

t_box *fill_tab(t_box *box, int line)
{
    int i = 0;
    int j = 0;
    int ln = 0;
    int car = (2 * line) + 2;
    for (int i = 0; i < (line + 2) ; i++){
        for (j = 0; j < (car - 1); j++) {
            box->tab[i][j] = '*';
            if (j > 0 && j < (car - 2) && i > 0 && i < (line + 1))
                box->tab[i][j] = ' ';
        }
        box->tab[i][j] = '\n';
        if (i > 0 && i < (line + 1))
            put_pip(box, line, i);
    }
    return (box);
}

void display_box_match(t_box *box)
{
    for (int i = 0; box->tab[i] != NULL; i++)
        my_putstr(box->tab[i]);
}

void free_tab(t_box *box, int line)
{
    for (int n = 0; n < (line + 3); n++)
        free(box->tab[n]);
}
