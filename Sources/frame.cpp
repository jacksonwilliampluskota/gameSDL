#include "frame.h"

void Frame::Draw(SDL_Texture* spritSheet, float x, float y)
{
  SDL_Rect dest;//destino onde vc vai querer desenhar o frame

  dest.x = x - offset.x;
  dest.y = y - offset.y;

  dest.w = clip.w;
  dest.h = clip.h;

  renderTexture(spritSheet, Globals::renderer, dest, &clip);

}

void Frame::loadFrame(ifstream &file, list<DataGroupType> &groupTypes){
	//Ok, we dragged these groupTypes allllll the way here, so we could construct groups on our frame to hold the data in
	GroupBuilder::buildGroups(groupTypes, frameData);


	string buffer;
	//frame - dud data saying this is a frame
	getline(file, buffer);
	//clip
	getline(file, buffer);
	stringstream ss;
	buffer = Globals::clipOffDataHeader(buffer);
	ss << buffer; //insere o valor de bufer dentro da stream
	ss >> clip.x >> clip.y >> clip.w >> clip.h; // usa a lib streamstring pra converter em um ou mais numeros ex: o de buffer venho 112 34 234 45 vai ser inserido nas variaveis x y w h em sequencias esses valores
	//offset/pivot
	getline(file, buffer);
	ss.clear();
	buffer = Globals::clipOffDataHeader(buffer);
	ss << buffer;
	ss >> offset.x >> offset.y;
	//duration
	getline(file, buffer);
	ss.clear();
	buffer = Globals::clipOffDataHeader(buffer);
	ss << buffer;
	ss >> duration;
	//index
	getline(file, buffer);
	ss.clear();
	buffer = Globals::clipOffDataHeader(buffer);
	ss << buffer;
	ss >> frameNumber;

	GroupBuilder::loadGroups(file, frameData);
}

