/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** navy_map
*/

#include "include/navy.h"

int f_x(char coord)
{
    int l_x = 0;

    for (; AP[l_x] && AP[l_x] != coord; ++l_x);
    l_x = l_x * 2 + 2;
    return (l_x);
}

int f_y(char *coord)
{
    int n_y = my_atoi(coord);

    n_y = n_y + 1;
    free(coord);
    return (n_y);
}

static void init_boat(boat_t *boat, char **co)
{
    boat->b_len = co[0][0];
    boat->b_y = f_y(my_cpy_st(co[1], co[1][0], 0));
    boat->b_x = f_x(co[1][0]);
    boat->e_y = f_y(my_cpy_st(co[2], co[2][0], 0));
    boat->e_x = f_x(co[2][0]);
}

static int put_boat_on_map(navy_t *nv, char *line)
{
    int nb = 0;
    char **co = my_otoo(line, ':', '\n', &nb);
    boat_t boat;
    if (boat_error(nv, co) != 0) {
        my_free_oo(co);
        return (84);
    }
    init_boat(&boat, co);
    nv->my_map[boat.b_y][boat.b_x] = boat.b_len;
    nv->my_map[boat.e_y][boat.e_x] = boat.b_len;
    for (;boat.b_x < boat.e_x; boat.b_x += 2)
        nv->my_map[boat.b_y][boat.b_x] = boat.b_len;
    for (;boat.b_x > boat.e_x; boat.b_x -= 2)
        nv->my_map[boat.b_y][boat.b_x] = boat.b_len;
    for (;boat.b_y < boat.e_y; ++boat.b_y)
        nv->my_map[boat.b_y][boat.b_x] = boat.b_len;
    for (;boat.b_y > boat.e_y; --boat.b_y)
        nv->my_map[boat.b_y][boat.b_x] = boat.b_len;
    my_free_oo(co);
    return (0);
}

int navy_map(navy_t *navy, int argc, char **argv)
{
    int fd = open(argv[argc - 1], O_RDONLY);
    char *line;

    create_map(navy, navy->my_map);
    create_map(navy, navy->enemi_map);
    if (fd == -1) {
        my_putrstr("File cannot be open\n", 0);
        return (84);
    }
    line = my_getline(fd);
    while (line) {
        if (put_boat_on_map(navy, line) != 0) {
            free(line);my_getline(ERROR_FREE_BUF);
            return (84);
        }
        free(line);
        line = my_getline(fd);
    }
    free(line);
    return (0);
}