#include "entity.h"

const int Entity::DIR_UP = 0, Entity::DIR_DOWN = 1, Entity::DIR_LEFT = 2, Entity::DIR_RIGHT = 3, Entity::DIR_NONE = -1;


    //virtual functions

    //SobEscreve pramin alguma coisa para algo usavel
    void Entity::update(){;}
    void Entity::draw()
    {
        //desenha frame atual
        if(currentFrame != NULL && active)
        {
          currentFrame->Draw(animSet->spriteSheet, x, y);
        }

        //Desenhar o collisionBox
        if(solid && Globals::debugging)
        {
            SDL_SetRenderDrawColor(Globals::renderer, 255, 0,0, SDL_ALPHA_OPAQUE);
            SDL_RenderDrawRect(Globals::renderer, &collisionBox);

        }
    }

    void Entity::move(float angle){
        moving = true;
        moveSpeed = moveSpeedMax;
        this->angle = angle;

        int newDirection = angleToDirection(angle);

        if(direction != newDirection)
        {
            direction = newDirection;

        }

    }
    /* void Entity::updateMovement(){;}
    void Entity::updateCollisionBox(){;}

    virtual void changeAnimation(int newState, bool resetFrameToBeginn) = 0;//função abstrata
    virtual void updateCollisions();

    //help functions
    static float distanceBetweenTwoRects(SDL_Rect &r1, SDL_Rect &r2);
    static float distanceBetweenTwoEntities(Entity *e1, Entity *e2);
    static float angleBetweenTwoEntities(Entity *e1, Entity *e2);
    static bool checkCollision(SDL_Rect cbox1m, SDL_Rect cbox2);
    static int angleToDirection(float angle);
    static float angleBetweenTwoPoints(float cx1, float cy1, float cx2, float cy2);
    static float angleBetweenTwoRects(SDL_Rect &r1, SDL_Rect &r2);

    //uma  gobla de entidades que podem ser referenciadas aqualquer hora
    static list<Entity*> entities;
    static bool EntityCompare(const Entity* const &a, const Entity* const &b);
    static void removeInactiveEntitiesFromList(list<Entity*> *entityList, bool deleteEntities);
    static void  removeFromAllList(list<Entity*> *entityList, bool deleteEntities); */