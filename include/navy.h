/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** navy
*/

#ifndef NAVY_H_
#define NAVY_H_

#define _GNU_SOURCE
#include "my.h"
#include "array.h"
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <time.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <my_getline.h>

#define SLEEP 10000000
#define AP "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define RW(X) ((X - 2) / 2)

typedef struct boat_s
{
    char b_len;
    unsigned char b_x;
    unsigned char b_y;
    unsigned char e_x;
    unsigned char e_y;
}boat_t;

typedef struct navy_s
{
    unsigned char height;
    unsigned char width;
    unsigned char square;
    unsigned char x;
    unsigned char y;
    int stay : 2;
    pid_t me;
    pid_t enemi;
    struct sigaction signal;
    struct timespec time;
    struct timespec remain;
    char **my_map;
    char **enemi_map;
}navy_t;

int navy_root(int argc, char **argv);

int init_all(navy_t *navy, struct sigaction *signal, int argc, char **argv);

int f_x(char coord);
int f_y(char *coord);
int navy_map(navy_t *navy, int argc, char **argv);

void create_map(navy_t *navy, char **map);

int navy_connection(navy_t *navy, struct sigaction *signal, int argc);

int navy_game(navy_t *navy, struct sigaction *signal, int argc);

void binary_signal(int sig, siginfo_t *info, void *s);
void send_square_value(struct sigaction *signal, navy_t *navy, int hit_square);
void recieved_square_value(struct sigaction *signal, navy_t *navy);

void input_interpretor(navy_t *navy, struct sigaction *signal, char *answer);
void recieved_interpretor(navy_t *navy, struct sigaction *signal);

int end_for_win(navy_t *navy, struct sigaction *signal);
int end_for_lose(navy_t *navy, struct sigaction *signal);

int boat_error(navy_t *navy, char **co);

#endif /* !NAVY_H_ */
