/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** navy_endwin
*/

#include "include/navy.h"


int end_for_win(navy_t *navy, struct sigaction *signal)
{
    recieved_square_value(signal, navy);
    if (navy->square == 1) {
        navy->stay = 0;
        return (1);
    }
    return (0);
}

int end_for_lose(navy_t *navy, struct sigaction *signal)
{
    if (my_count_too(navy->my_map, '1', '9') - 8 == 0) {
        send_square_value(signal, navy, 1);
        navy->stay = 0;
        return (1);
    }
    send_square_value(signal, navy, 0);
    return (0);
}