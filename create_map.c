/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** navy_create_map
*/

#include "include/navy.h"

static void create_first_line(navy_t *nv, char **map)
{
    map[nv->y][nv->x] = ' ';
    if (nv->height > 12)
        map[nv->y][++nv->x] = ' ';
    map[nv->y][++nv->x] = '|';
    map[nv->y][++nv->x] = 'A';
    for (char letter = 'B'; nv->x < nv->width - 2; ++letter) {
        map[nv->y][++nv->x] = ' ';
        map[nv->y][++nv->x] = letter;
    }
    map[nv->y++][++nv->x] = '\0';
}

static void create_second_line(navy_t *nv, char **map)
{
    for (nv->x = 0; nv->x < nv->width - 1; ++nv->x) {
        map[nv->y][nv->x] = '-';
    }
    if (nv->height > 12) {
        map[nv->y][2] = '+';
        map[nv->y][nv->width - 1] = '-';
        map[nv->y][nv->width] = '\0';
    } else {
        map[nv->y][1] = '+';
        map[nv->y][nv->width - 1] = '\0';
    }
}

static void create_body_game(navy_t *nv, char **map)
{
    unsigned char number = '1';
    unsigned char ten = '0';

    for (nv->y = 2; nv->y < nv->height; ++nv->y, ++number) {
        nv->x = 0;
        if (number == ':') {
            number = '0';
            ++ten;
        }
        if (nv->height > 12)
            map[nv->y][nv->x++] = ten;
        map[nv->y][nv->x++] = number;
        map[nv->y][nv->x++] = '|';
        map[nv->y][nv->x++] = '.';
        for (; nv->x < nv->width - 1; ++nv->x) {
            map[nv->y][nv->x++] = ' ';
            map[nv->y][nv->x] = '.';
        }
        map[nv->y][nv->x] = '\0';
    }
}

void create_map(navy_t *navy, char **map)
{
    navy->x = 0;
    navy->y = 0;
    create_first_line(navy, map);
    create_second_line(navy, map);
    create_body_game(navy, map);
}