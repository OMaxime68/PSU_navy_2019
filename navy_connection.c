/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** navy_connection
*/

#include "include/navy.h"

int global_value = 0;

void get_info(int a, siginfo_t *info, void *s)
{
    global_value = info->si_pid;
}

int connection_to_player_two(struct sigaction *signal, navy_t *navy)
{
    signal->sa_sigaction = get_info;
    sigaction(SIGUSR1, signal, NULL);
    my_putstr("waiting for enemy connection...\n");
    pause();
    navy->enemi = global_value;
    my_putstr("\nenemy connected\n");
    return (0);
}

int connection_to_player_one(struct sigaction *signal, navy_t *navy)
{
    signal->sa_sigaction = get_info;
    sigaction(SIGUSR1, signal, NULL);
    kill(navy->enemi, SIGUSR1);
    my_putstr("sucessfully connected\n");
    kill(navy->enemi, SIGUSR1);
    return (0);
}

int navy_connection(navy_t *navy, struct sigaction *signal, int argc)
{
    nl_putstr(my_strcat_bside("my_pid: ", my_intchar(navy->me), "\n", 3));
    if (argc == 2 && connection_to_player_two(signal, navy) != 0)
        return (84);
    else if (argc == 3 && connection_to_player_one(signal, navy) != 0)
        return (84);
    return (0);
}