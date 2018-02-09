#ifndef FRAME_H
#define FRAME_H

#include <iostream>
#include <list>
#include <fstream>
#include <sstream>
#include<SDL2/SDL.h>
#include "drawing_functions.h"
#include "globals.h"
#include "groupBuilder.h"

using namespace std;

class Frame
{
  public:
    int frameNumber; // index do frame
    SDL_Rect clip; //para pegar a area do do sprite para o  frame
    float duration; //duraçao do frame
    SDL_Point offset; //Pivo ou ancora da imagem
    list<Group*>frameData;

    void Draw(SDL_Texture* spriteSheet, float x, float y);

    void loadFrame (ifstream &file, list<DataGroupType> &groupTypes);
};

#endif