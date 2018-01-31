#include "Sources/cleanup.cpp"
#include "Sources/res_path.cpp"
#include "Sources/drawing_functions.cpp"
#include "SDL2/SDL_mixer.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 352;

int main(int argc, char **argv)
{
  //Variavel para iniciar Window
  SDL_Window *window;
  SDL_Renderer *renderer;
  SDL_Texture* texture;

  //Iniciar SDL
  if ( SDL_Init(SDL_INIT_EVERYTHING) != 0 )
  {
    cout << "Erro ao iniciar SDL!!"<< endl;
    return 1;
  }

  //Iniciar janela
  window = SDL_CreateWindow("Cyborg battle", SDL_WINDOWPOS_CENTERED,
                            SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH,
                            SCREEN_HEIGHT, SDL_WINDOW_SHOWN);//SDL_WINDOW_SHOWN | SLD_WINDOW_FULLSCREEN

  if(window == nullptr)
  {
    SDL_Quit();
    cout << "Erro ao criar Window!!"<< endl;
    return 1;
  }

  //Iniciar Render
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

  if(renderer == nullptr)
  {
    SDL_Quit();
    cleanup(window);//Classe que chama a função destroi do objeto que for adicionado por exemplo window, surface ou render.
    cout << "Erro ao criar render!!"<< endl;
    return 1;
  }

  //Esse é o tamanho pra desenhar as coisas, antes nos escalamos ele pra o tamanho da tela escrito in createWindow
  SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);

  //iniciado imagens
  if( ( IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG ) != IMG_INIT_PNG )
  {
    SDL_Quit();
    cout << "Imagem SDL ao inicio" << endl;
    return 1;
  }

  //Iferificar se a lib de texto com fite esta correta
  if(TTF_Init() != 0)
  {
    SDL_Quit();
    cout << "Nao foi incializado corretamente lib de texto e fonte" <<endl;
    return 1;

  }

  //iniciar SDL-mixer
  if(Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
  {
    SDL_Quit();
    cout << "nao foi possivel inicilizar lib mix" << endl;
    return 1;

  }

  //caregar texturar para desenhar
  string resPath = getResourcePath();

  texture = loadTexture(resPath + "map.png", renderer);

  //rodar o game por 5000 ticks (5000ms)
  while(SDL_GetTicks() < 5000)
  {
    //limpa a tela a cada loop
    SDL_RenderClear(renderer);

    //desenha na tela
    renderTexture(texture, renderer, 0, 0);

    //mostrar imagem que estamos renderizando
    SDL_RenderPresent(renderer);
  }

  cleanup(renderer);
  cleanup(window);
  cleanup(texture);

  SDL_Quit();

  return 0;
}

//g++ main.cpp -std=gnu++0x -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer -o build/cyborg