/*
** EPITECH PROJECT, 2023
** scoregestio$
** File description:
** scoegestion
*/

#include "../includes/my.h"
#include <SFML/Graphics.h>

void catvalue(int vie, int *length, char *scoreValue)
{
    int temp = vie;

    *length = 0;
    while (temp != 0) {
        temp /= 10;
        (*length)++;
    }
    for (int i = *length - 1; i >= 0; i--) {
        scoreValue[i] = vie % 10 + '0';
        vie /= 10;
    }
    scoreValue[*length] = '\0';
}

void printlifevalue(SFMLObjects* csfml)
{
    sfFont* font = sfFont_createFromFile("img/arial.ttf");
    char scoreValue[100];
    int vie = csfml->vie;
    int length = 0;
    int temp = vie;

    csfml->lifeText = sfText_create();
    catvalue(vie, &length, scoreValue);
    scoreValue[length] = '\0';
    sfText_setString(csfml->lifeText, scoreValue);
    sfText_setFont(csfml->lifeText, font);
    sfText_setCharacterSize(csfml->lifeText, 100);
    sfText_setPosition(csfml->lifeText, (sfVector2f){1700, 907});
    sfText_setColor(csfml->lifeText, sfBlack);
    sfRenderWindow_drawText(csfml->window, csfml->lifeText, NULL);
    sfText_destroy(csfml->lifeText);
    sfFont_destroy(font);
}

void printscorevalue(SFMLObjects* csfml)
{
    sfFont* font = sfFont_createFromFile("img/arial.ttf");
    char scoreValue[10];
    int score = csfml->score;
    int length = 0;
    int temp = score;

    csfml->scoreText = sfText_create();
    catvalue(score, &length, scoreValue);
    scoreValue[length] = '\0';
    sfText_setString(csfml->scoreText, scoreValue);
    sfText_setFont(csfml->scoreText, font);
    sfText_setCharacterSize(csfml->scoreText, 100);
    sfText_setPosition(csfml->scoreText, (sfVector2f){1000, 907});
    sfText_setColor(csfml->scoreText, sfBlack);
    sfRenderWindow_drawText(csfml->window, csfml->scoreText, NULL);
    sfText_destroy(csfml->scoreText);
    sfFont_destroy(font);
}

void printscore(SFMLObjects* csfml)
{
    sfFont* font = sfFont_createFromFile("img/arial.ttf");

    csfml->text = sfText_create();
    sfText_setString(csfml->text, "Score : ");
    sfText_setFont(csfml->text, font);
    sfText_setCharacterSize(csfml->text, 100);
    sfText_setPosition(csfml->text, (sfVector2f){650, 907});
    sfText_setColor(csfml->text, sfBlack);
    sfRenderWindow_drawText(csfml->window, csfml->text, NULL);
    sfText_destroy(csfml->text);
    sfFont_destroy(font);
}

void printlife(SFMLObjects* csfml)
{
    sfFont* font = sfFont_createFromFile("img/arial.ttf");

    csfml->text2 = sfText_create();
    sfText_setString(csfml->text2, "Vie : ");
    sfText_setFont(csfml->text2, font);
    sfText_setCharacterSize(csfml->text2, 100);
    sfText_setPosition(csfml->text2, (sfVector2f){1500, 907});
    sfText_setColor(csfml->text2, sfBlack);
    sfRenderWindow_drawText(csfml->window, csfml->text2, NULL);
    sfText_destroy(csfml->text2);
    sfFont_destroy(font);
}
