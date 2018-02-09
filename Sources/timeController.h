#ifndef TIMECONTROLLER_H
#define TIMECONTROLLER_H

#include <iostream>
#include <SDL2/SDL.h>

class TimeContorller
{

  public:
    enum STATUS{ PLAY_STATE, PAUSE_STATE};

    int timeState;
    Uint32 lastUpdate; // ultima vez que foi iniciado o tick do SDL pra contorlar frame
    float dT; //delta time; em segundos

    TimeContorller();

    void updateTime();
    void pause();
    void resume();
    void reset();

    static TimeContorller timeContorller;

};

#endif