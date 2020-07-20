/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** navy_init
*/

#include "include/navy.h"

static int init_navy(navy_t *navy, int argc, char **argv)
{
    navy->square = 0;
    navy->time.tv_sec = 0;
    navy->height = 8 + 2;
    navy->width = 8 * 2 + 2;
    navy->time.tv_nsec = SLEEP;
    navy->me = getpid();
    navy->my_map = my_malloc_db(navy->height, navy->width);
    navy->enemi_map = my_malloc_db(navy->height, navy->width);
    if (argc == 3)
        navy->enemi = my_atoi(argv[1]);
    if (navy->enemi_map == NULL || navy->my_map == NULL) {
        my_putrstr("Error in malloc\n", 0);
        return (84);
    }
    return (0);
}

static void init_signal(struct sigaction *signal)
{
    sigemptyset(&signal->sa_mask);
    signal->sa_flags = SA_SIGINFO;
}

int init_all(navy_t *navy, struct sigaction *signal, int argc, char **argv)
{
    if (init_navy(navy, argc, argv) != 0)
        return (84);
    init_signal(signal);
    return (0);
}
