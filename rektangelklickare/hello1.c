#include "hej.h"

int startTime = 0;

int main(void) {
  startTime = time(NULL);
    
  SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Start", "Nu börjas det.", NULL);

  if(atexit(QuitTwo)) {
    fprintf(stderr, "kan inte sätta exitfunktion\n");
    exit(EXIT_FAILURE);
  }
  if(atexit(SDL_Quit)) {
    fprintf(stderr, "kan inte sätta exitfunktion\n");
    exit(EXIT_FAILURE);
  }
  if(atexit(QuitOne)) {
    fprintf(stderr, "kan inte sätta exitfunktion\n");
    exit(EXIT_FAILURE);
  }
  
  SDL_Init(SDL_INIT_EVERYTHING);

  SDL_Window *screen = NULL;
  SDL_Renderer *renderer;
  
  if(SDL_CreateWindowAndRenderer(500, 500, 0 /* SDL_WINDOW_MAXIMIZED | SDL_WINDOW_RESIZABLE */, &screen, &renderer)) {
    exit(EXIT_FAILURE);
  }
  SDL_SetWindowTitle(screen, "Hej");

  srand((int)startTime);

  RektangelFunktion(screen, renderer);
  
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(screen);
  exit(EXIT_SUCCESS);

}
