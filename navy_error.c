/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** navy_error
*/

#include "include/navy.h"

static int basic_verification(char **co)
{
    if (my_length_oo(co) != 3) {
        my_putrstr("Too fiew information in a line\n", 0);
        return (1);
    }
    if (my_strlen(co[0]) != 1 || my_isnum(co[0][0]) != 0) {
        my_putrstr("Impossible length of ship\n", 0);
        return (1);
    }
    if (my_strlen(co[1]) != 2 || my_strlen(co[2]) != 2 ||
    my_isalpha(co[1][0], 'A', 'H') != 0 ||
    my_isalpha(co[2][0], 'A', 'H') != 0 ||
    my_isin(my_cpy_st(co[1], co[1][0], 0), '0', '9', 1) ||
    my_isin(my_cpy_st(co[2], co[2][0], 0), '0', '9', 1)) {
        my_putrstr("Impossible input of square\n", 0);
        return (1);
    }
    return (0);
}

static int advanced_verification(char **co)
{
    int len = my_atoi(co[0]) - 1;
    int l_one = co[1][0];
    int l_two = co[2][0];
    int n_one = nl_atoi(my_cpy_st(co[1], co[1][0], 0));
    int n_two = nl_atoi(my_cpy_st(co[2], co[2][0], 0));

    if ((l_one != l_two && n_one != n_two) ||
        (l_one == l_two && n_one == n_two)) {
        my_putrstr("Invalid start or/and end point\n", 0);
        return (1);
    }
    if (len != l_one - l_two && len != l_two - l_one &&
        len != n_one - n_two && len != n_two - n_one) {
        my_putrstr("Len of ship written doens't correspond to len calculate\n",
        0);
        return (1);
    }
    return (0);
}

int boat_error(navy_t *navy, char **co)
{
    if (basic_verification(co) != 0)
        return (84);
    if (advanced_verification(co) != 0)
        return (84);
   return (0);
}