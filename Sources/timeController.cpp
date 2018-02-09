#include "timeController.h"

TimeContorller::TimeContorller()
{
  dT = 0;
  lastUpdate = 0;
  timeState = PLAY_STATE;

}

void TimeContorller::updateTime()
{

  if (timeState == PAUSE_STATE)
  {
    dT = 0;

  }
  else
  {

    Uint32 timeDiff = SDL_GetTicks() - lastUpdate;
    dT = timeDiff / 1000.0; //divide os milesegundos por 1000 ex: 104 ticks = 0.104 segundos
  }

  lastUpdate = SDL_GetTicks();

}

void TimeContorller::pause()
{
  timeState = PAUSE_STATE;

}

void TimeContorller::resume()
{

  timeState = PLAY_STATE;

}

void TimeContorller::reset()
{

  dT = 0;
  lastUpdate = SDL_GetTicks();

}

//Criar um objeto global do TimeContorller para usar em qualquer lugar
TimeContorller TimeContorller::timeContorller;