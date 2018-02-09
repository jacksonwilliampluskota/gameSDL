#include "animation.h"

    Animation::Animation(string name)
    {
      this->name = name;

    }

    int Animation::getNextFrameNumber(int frameNumber)
    {
      if(frameNumber + 1 < frames.size())
        return frameNumber + 1;
      else
        return 0;

    }

    Frame* Animation::getNextFrame(Frame* frame)
    {
      return getFrame(getNextFrameNumber(frame->frameNumber));

    }

    int Animation::getEndFrame()
    {
      return frames.size() - 1;

    }

    Frame* Animation::getFrame(int frameNumber)
    {

      if(frames.size() == 0)
        return NULL;

      list<Frame>::iterator i = frames.begin();//iterator é um maneira de fazer varedura do objeto e pegar ca posiçaõ d alist ou array, e pegando o pointer dele .aqui pegamos o primeiro frame

      int counter = 0;

      for(counter = 0; counter < frameNumber && counter < frames.size() - 1; counter ++)
      {
        i++;//seguificaque estou passndo pro proximo objeto da lista de frames

      }

      Frame *frame = &(*i);//faz com que o opnteiro no frame vire um ponte da noss lista de frames eu acho que é isso

      return frame;

    }

  void Animation::loadAnimation(ifstream &file, list<DataGroupType> &groupTypes){
    getline(file, name);

    string buffer;
    getline(file, buffer);

    stringstream ss;

    buffer = Globals::clipOffDataHeader(buffer);
    ss << buffer;

    int numberOfFrames;
    ss >> numberOfFrames;

    for (int i = 0; i < numberOfFrames; i++){
      Frame newFrame;
      newFrame.loadFrame(file, groupTypes);
      frames.push_back(newFrame);
    }


  }