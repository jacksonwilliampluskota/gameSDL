#ifndef ANIMATIONSET_H
#define ANIMATIONSET_H

#include "animation.h"

using namespace std;

class AnimationSet
{

  public:
    string imageName;
    SDL_Texture* spriteSheet;
    SDL_Texture* whiteSpriteSheet = NULL;//esse spritesheet vai ser usado para mostrar os danos no jogo
    list<Animation> animations;

    ~AnimationSet();//Destroctor limpa qualquer memoria dinamica

    Animation* getAnimation(string name);


    void loadAnimationSet(string fileName, list<DataGroupType> &groupTypes, bool setColorKey = false, int transparentPixelIndex = 0, bool createWhiteTexture = false);


};



#endif