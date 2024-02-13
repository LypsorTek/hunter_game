/*
** EPITECH PROJECT, 2023
** sprite
** File description:
** sprite
*/

#include "../includes/my.h"
#include <SFML/Graphics.h>

void initsprite(SFMLObjects* csfml)
{
    sfVideoMode mode = {1920, 1080, 64};
    csfml->window = sfRenderWindow_create(mode, "My Hunter",
    sfResize | sfClose, NULL);
    csfml->texture = sfTexture_createFromFile("img/map2.jpeg", NULL);
    csfml->sprite = sfSprite_create();
    csfml->duck = sfTexture_createFromFile("img/canard2.png", NULL);
    csfml->ducksprite = sfSprite_create();
    sfSprite_setTexture(csfml->ducksprite, csfml->duck, sfTrue);
    sfSprite_setTexture(csfml->sprite, csfml->texture, sfTrue);
}

void renderall(SFMLObjects* csfml)
{
    sfRenderWindow_clear(csfml->window, sfBlack);
    sfRenderWindow_drawSprite(csfml->window, csfml->sprite, NULL);
    sfRenderWindow_drawSprite(csfml->window, csfml->ducksprite, NULL);
    printscore(csfml);
    printlife(csfml);
    printscorevalue(csfml);
    printlifevalue(csfml);
    sfRenderWindow_display(csfml->window);
}

void cleanall(SFMLObjects* csfml)
{
    sfSprite_destroy(csfml->sprite);
    sfSprite_destroy(csfml->ducksprite);
    sfTexture_destroy(csfml->texture);
    sfTexture_destroy(csfml->duck);
    sfRenderWindow_destroy(csfml->window);
}
