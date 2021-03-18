/*
** EPITECH PROJECT, 2019
** my_matchstick
** File description:
** matchstick prototype
*/

#ifndef MATCHSTICK_H_
#define MATCHSTICK_H_

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>

typedef struct t_box t_box;
struct t_box
{
    char **tab;
    int line_p;
    int match_p;
};

typedef struct t_smart t_smart;
struct t_smart
{
    int line_ai;
    int match_ai;
    int winner;
    int error;
    int value;
};

int bad_stuff(char *str);
void match_movement(int match);
t_smart playing(t_smart smart, t_box box, int line, int match);
t_smart *initialisation(t_smart *smart, int line, int match);
void ai_movement(t_smart *smart);
t_box *line_and_match_ai(t_smart *smart, t_box *box, int line, int match);
int check_if_empty(t_box *box);
void free_tab(t_box *box, int line);
void display_box_match(t_box *box);
int line_of_player(t_box *box, int line);
int check_line(t_box *box, int line);
t_smart loop_game(t_smart *smart, t_box *box, int line, int match);
t_smart *loop_game_inside(t_smart *smart, t_box *box, int line, int match);
int check_empty_line(char *str);
int match_of_player(t_box *box, int match, int line);
int check_match(t_box *box, int match, int line);
int player_instruction(t_box *box, int line, int match);
int my_getnbr(char const *str);
t_box *malloc_tab(t_box *box, int line);
t_box *fill_tab(t_box *box, int line);
void my_putchar(char c);
void put_pip(t_box *box, int line, int i);
int my_strlen(char *);
int my_putstr(char const *);
int my_putnbr(int n);
int remover_of_match(t_box *box, int line, int match);
int count_pip(char *str, int line);
#endif
