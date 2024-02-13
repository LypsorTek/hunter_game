/*
** EPITECH PROJECT, 2023
** hunter
** File description:
** hunter
*/

#include "../includes/my.h"
#include <SFML/Graphics.h>
#include <stdio.h>

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    int j = 0;

    while (s1[i] && s2[j]) {
        if (s1[i] != s2[j])
            return (s1[i] - s2[j]);
        i++;
        j++;
    }
    return (0);
}

void managewindow(SFMLObjects* csfml)
{
    while (sfRenderWindow_pollEvent(csfml->window, &csfml->event)) {
        if (csfml->event.type == sfEvtClosed)
            sfRenderWindow_close(csfml->window);
    }
}

int main(int argc, char **argv)
{
    SFMLObjects csfml;

    csfml.score = 0;
    csfml.vie = 100;
    if (argc > 1) {
        if (my_strcmp(argv[1], "-h") == 0) {
            help();
            return 0;
        }
    }
    initsprite(&csfml);
    while (sfRenderWindow_isOpen(csfml.window)) {
        managewindow(&csfml);
        getspritepos(&csfml, 0.1f);
        animesprite(&csfml);
        renderall(&csfml);
    }
    cleanall(&csfml);
    return 0;
}
