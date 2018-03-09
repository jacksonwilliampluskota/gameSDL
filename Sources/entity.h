#ifndef ENTITY_H
#define ENTITY_H

#include "globals.h"
#include "timeController.h"
#include "animationSet.h"

//classe abstrata.Nao pode ser instaciada a um objeto do tipo Entity ex: nao d apra fazer Entity e;
class Entity {
  public:
    static const int DIR_UP, DIR_DOWN,DIR_LEFT, DIR_RIGHT, DIR_NONE;

    int state;

    float x, y;
    int derection;
    bool solid = true;
    bool collideWithSolids = true;
    bool active = true;
    string type ="entity";
    bool moving;
    float angle;
    float moveSpeed;
    float moveSpeedMax;
    float slideAngle;
    float slideAmount;
    float moveLerp = 4; //?
    float totalXMove, totalYMove;
    SDL_Rect collisionBox;
    SDL_Rect lastCollisionBox;

    int collisionBoxW, collisionBoxH; //vai ser o nosso collission box default
    float collisionBoxYOffset; //para o meu vlaor y da entity, e onde eu deveria setar essa collisoin box

    AnimationSet *animSet; // setar todas as animações nessa entidade que vc tem
    Animation *currentAnim;
    Frame *currentFrame;
    float frameTimer;

    //virtual functions
    virtual void update();
    virtual void draw();

    virtual void move(float angle);
    virtual void updateMovement();
    virtual void updateCollisionBox();

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
    static void  removeFromAllList(list<Entity*> *entityList, bool deleteEntities);

};
#endif