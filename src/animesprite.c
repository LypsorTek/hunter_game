/*
** EPITECH PROJECT, 2023
** animesprite
** File description:
** animeswprite
*/

#include "../includes/my.h"
#include <SFML/Graphics.h>

void getspritepos(SFMLObjects* csfml, float speed)
{
    sfVector2f velocity = {speed, 0.0f};
    sfVector2u windowSize;
    sfFloatRect duckBounds;
    sfVector2f duckPosition ;

    sfSprite_move(csfml->ducksprite, velocity);
    duckPosition = sfSprite_getPosition(csfml->ducksprite);
    duckBounds = sfSprite_getGlobalBounds(csfml->ducksprite);
    windowSize = sfRenderWindow_getSize(csfml->window);
    if (duckBounds.left + duckBounds.width > windowSize.x
    || duckBounds.left < 0) {
        velocity.x = -velocity.x;
        sfSprite_move(csfml->ducksprite, velocity);
    }
}

void defeat(SFMLObjects* csfml)
{
    sfVector2u windowSize = sfRenderWindow_getSize(csfml->window);
    sfFloatRect duckBounds = sfSprite_getGlobalBounds(csfml->ducksprite);
    sfVector2f duckPosition = sfSprite_getPosition(csfml->ducksprite);

    if (duckBounds.left + duckBounds.width > windowSize.x) {
        csfml->vie -= 10;
        sfSprite_setPosition(csfml->ducksprite, (sfVector2f){0.0f,
        (float)(rand() % windowSize.y)});
    }
}

void life(SFMLObjects* csfml)
{
    if (csfml->vie == 0) {
        sfRenderWindow_close(csfml->window);
    }
}

void mouseclick(SFMLObjects* csfml)
{
    sfVector2u windowSize = sfRenderWindow_getSize(csfml->window);
    sfVector2i mousePosition = sfMouse_getPositionRenderWindow(csfml->window);
    sfFloatRect spriteBounds = sfSprite_getGlobalBounds(csfml->ducksprite);
    sfVector2f newPosition = {0.0f, (float)(rand() % windowSize.y)};
    float speed = 10.0f;

    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (sfFloatRect_contains(&spriteBounds, mousePosition.x,
        mousePosition.y)) {
            sfSprite_setPosition(csfml->ducksprite, newPosition);
            csfml->score += 10;
            csfml->vie += 10;
            getspritepos(csfml, speed);
        } else {
            csfml->vie -= 1;
            life(csfml);
        }
    }
}

void animesprite(SFMLObjects* csfml)
{
    static sfClock* clock = NULL;
    static float elapsedTime = 10.5f;
    static int currentFrame = 0;
    static int frameCount = 3;
    static int frameWidth = 105;
    static int frameHeight = 100;
    int frameX = currentFrame * frameWidth;
    sfIntRect textureRect = {frameX, 0, frameWidth, frameHeight};
    sfVector2u windowSize = sfRenderWindow_getSize(csfml->window);

    if (clock == NULL) {
        clock = sfClock_create();
    }
    elapsedTime += sfTime_asSeconds(sfClock_restart(clock));
    sfSprite_setTextureRect(csfml->ducksprite, textureRect);
    currentFrame = (currentFrame + 1) % frameCount;
    elapsedTime = 10.0f;
    mouseclick(csfml);
    defeat(csfml);
}
