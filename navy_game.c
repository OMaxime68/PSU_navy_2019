/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** navy_game
*/

#include "include/navy.h"

static void game_display(navy_t *navy)
{
    my_putstr("\nmy positions:\n");
    my_putoo(navy->my_map);
    my_putstr("\nenemy's positions:\n");
    my_putoo(navy->enemi_map);
}

static int input_waiting(navy_t *navy, char **answer)
{
    while (1) {
        my_putstr("\nattack: ");
        *answer = my_getline(0);
        if (my_strcmp(*answer, "ctrl d", 0) == 0)
            return (5);
        my_clean(*answer, ' ', '\t');
        my_clean(*answer, '\n', 0);
        if (my_isalpha(*answer[0], 'A', 'H') == 0 &&
            my_isin(my_cpy_st(*answer, *answer[0], 0), '1', '8', 1) == 0)
            break;
        my_putstr("wrong position");
    }
    return (0);
}

static int player_one(navy_t *navy, struct sigaction *signal)
{
    char *answer = NULL;

    while (navy->stay) {
        game_display(navy);
        if (input_waiting(navy, &answer) == 5)
            return (0);
        input_interpretor(navy, signal, answer);
         if (end_for_win(navy, signal) != 0)
            continue;
        recieved_interpretor(navy, signal);
         if (end_for_lose(navy, signal) != 0)
            continue;
        free(answer);
    }
    free(answer);
    return (0);
}

static int player_two(navy_t *navy, struct sigaction *signal)
{
    char *answer;

    while (navy->stay) {
        game_display(navy);
        recieved_interpretor(navy, signal);
        if (end_for_lose(navy, signal) != 0)
            return (0);
        if (input_waiting(navy, &answer) == 5)
            return (0);
        input_interpretor(navy, signal, answer);
         if (end_for_win(navy, signal) != 0)
            continue;
        free(answer);
    }
    free(answer);
    return (0);
}

int navy_game(navy_t *navy, struct sigaction *signal, int argc)
{
    navy->stay = 1;
    signal->sa_sigaction = binary_signal;
    if (argc == 2)
        return (player_one(navy, signal));
    else if (argc == 3)
        return (player_two(navy, signal));
    return (84);
}