#include <SDL.h>
#include <stdlib.h>

int main(void) {
  SDL_Init(SDL_INIT_EVERYTHING);
  SDL_DisplayMode skarm;
  SDL_GetDesktopDisplayMode(0, &skarm);
  printf("Skärminfo:\nw: %d\nh: %d\nfrekv.: %d\n", skarm.w, skarm.h, skarm.refresh_rate);
  return 0;
}
