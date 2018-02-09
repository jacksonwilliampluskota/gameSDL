#ifndef ANIMATION_H
#define ANIMATION_H

#include "frame.h"

using namespace std;

class Animation
{
  public:
    string name;//nome da animação
    list<Frame> frames;//list de nosso frmaes

    Animation(string name = "");

    int getNextFrameNumber(int frameNumber); // retorna o proximo numero do frame na lista

    Frame *getNextFrame(Frame* frame);

    int getEndFrame();//retorna o numero do ultimo frame

    Frame* getFrame(int frameNumber);// pega o numero de do frame que esta sendo usado

    void loadAnimation(ifstream &file, list<DataGroupType> &groupTypes);
};

#endif