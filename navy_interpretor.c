/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** navy_interpretor
*/

#include "include/navy.h"

void input_interpretor(navy_t *navy, struct sigaction *signal, char *answer)
{
    unsigned char y = f_y(my_cpy_st(answer, answer[0], 0));
    unsigned char x = f_x(answer[0]);
    unsigned char square = y * navy->width + x;

    send_square_value(signal, navy, square);
    recieved_square_value(signal, navy);
    nl_putstr(my_cpy_lim(answer, '\n', 0));
    if (navy->square == 1) {
        navy->enemi_map[y][x] = 'x';
        my_putstr(": hit\n");
    } else {
        navy->enemi_map[y][x] = 'o';
        my_putstr(": missed\n");
    }
}

void recieved_interpretor(navy_t *navy, struct sigaction *signal)
{
    unsigned char y = 0;
    unsigned char x = 0;

    my_putstr("\nwaiting for enemy's attack...\n");
    recieved_square_value(signal, navy);
    y = navy->square / navy->width;
    x = navy->square % navy->width;
    write(1, &AP[RW(x)], 1);
    nl_putstr(my_intchar(y - 1));
    if (my_isnum(navy->my_map[y][x]) == 0) {
        navy->my_map[y][x] = 'x';
        my_putstr(": hit\n");
        send_square_value(signal, navy, 1);
    } else {
        navy->my_map[y][x] = 'o';
        my_putstr(": missed\n");
        send_square_value(signal, navy, 0);
    }
}
