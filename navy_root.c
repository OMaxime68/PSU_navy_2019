/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** navy_root
*/

#include "include/navy.h"

void my_free_all(navy_t *navy)
{
    my_free_oo(navy->my_map);
    my_free_oo(navy->enemi_map);
}

int navy_creation_root(navy_t *navy, struct sigaction *signal, int argc,
char **argv)
{
    if (init_all(navy, signal, argc, argv) != 0)
        return (84);
    if (navy_map(navy, argc, argv) != 0)
        return (84);
    if (navy_connection(navy, signal, argc) != 0)
        return (84);
    return (0);
}

int navy_root(int argc, char **argv)
{
    navy_t navy;
    struct sigaction signal;

    if (navy_creation_root(&navy, &signal, argc, argv) != 0) {
        my_free_all(&navy);
        return (84);
    }
    navy_game(&navy, &signal, argc);
    my_free_all(&navy);
    return (0);
}