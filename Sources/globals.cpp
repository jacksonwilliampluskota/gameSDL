#include "globals.h"

using namespace std;

const float Globals::PI = 3.14159;

bool Globals::debugging = true;

int Globals::ScreenWidth = 640, Globals::ScreenHeight = 352, Globals::ScreenScale = 2;

SDL_Renderer* Globals::renderer = NULL;


string Globals::clipOffDataHeader( string data)
{

  int pos = data.find(":", 0);

  if(pos != -1)
  {
    data = data.substr(pos+1, data.length() - pos+2);
  }

  return data;

}