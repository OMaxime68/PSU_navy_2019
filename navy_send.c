/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** navy_send
*/

#include "include/navy.h"

int value = 0;

void binary_signal(int sig, siginfo_t *info, void *s)
{
    if (sig == SIGUSR1)
        value = 1;
    else if (sig == SIGUSR2)
        value = 0;
}

void send_square_value(struct sigaction *signal, navy_t *navy, int hit_square)
{
    for (int ref = 1; ref != 256; ref = ref << 1) {
        nanosleep(&navy->time, &navy->remain);
        if (hit_square & ref)
            kill(navy->enemi, SIGUSR1);
        else
            kill(navy->enemi, SIGUSR2);
    }
}

void recieved_square_value(struct sigaction *signal, navy_t *navy)
{
    sigaction(SIGUSR1, signal, NULL);
    sigaction(SIGUSR2, signal, NULL);
    navy->square = 0;
    for (int i = 0; i < 8; ++i) {
        pause();
        if (value & 1)
            navy->square = navy->square | (1 << i);
    }
}