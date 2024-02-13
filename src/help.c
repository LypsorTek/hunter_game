/*
** EPITECH PROJECT, 2023
** aide
** File description:
** help
*/

#include "../includes/my.h"
#include <unistd.h>

void help(void)
{
    write(1, "Duck Hunt\n", 10);
    write(1, "USAGE\n", 6);
}
