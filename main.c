/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** main
*/

#include "include/navy.h"

int main(int argc, char **argv)
{
    if (argc < 2 || argc > 3) {
        my_putrstr("Too few or too many arguments\n", 0);
        return (84);
    }
    return (navy_root(argc, argv));
}