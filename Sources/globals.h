#ifndef GLOBALS_H
#define GLOBALS_H

#include <string>
#include <iostream>
#include<SDL2/SDL.h>
#include "randomNumber.h"

class Globals{
  public:
    //para adicionar o valor de pi
    static const float PI;

    static bool debugging;

    static int ScreenWidth, ScreenHeight, ScreenScale;

    static SDL_Renderer* renderer;

    //pegar o clip e tirar a palavra e deixar só os valores acho que é isso
    static string clipOffDataHeader(string data);
};

#endif