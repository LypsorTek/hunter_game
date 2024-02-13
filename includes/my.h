/*
** EPITECH PROJECT, 2023
** includes
** File description:
** includes
*/

#ifndef myh
    #define myh

    #include <SFML/Graphics.h>

typedef struct {
    sfRenderWindow* window;
    sfTexture* texture;
    sfSprite* sprite;
    sfTexture* duck;
    sfSprite *ducksprite;
    sfText* text2;
    sfText* text;
    sfEvent event;
    int score;
    int vie;
    sfText* scoreText;
    sfText* lifeText;
} SFMLObjects;

void getspritepos(SFMLObjects* csfml, float speed);
void animesprite(SFMLObjects* csfml);
void help(void);
void printscore(SFMLObjects* csfml);
void initsprite(SFMLObjects* csfml);
void renderall(SFMLObjects* csfml);
void cleanall(SFMLObjects* csfml);
void printlife(SFMLObjects* csfml);


#endif /* !myh */
