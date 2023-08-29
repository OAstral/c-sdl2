#include "hej.h"

void QuitOne(void) {
  printf("Skall stänga.\n");
}
void QuitTwo(void) {
  printf("Efter SDL_Quit.\n");
}

extern int startTime;
int RektangelFunktion(SDL_Window *screen, SDL_Renderer *renderer) {
  
  SDL_Rect rektangel;
  SDL_Event event;
  
  SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "På g", "Dags att rita.", screen);

  int notQuit = 1;
  int notPressed = 1;
  while(notQuit) {
    printf("Försöker rita.\n");
    {
      SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
      SDL_RenderClear(renderer);
      rektangel.x = rand() % 100 + 20;
      rektangel.y = rand() % 100 + 20;
      rektangel.h = 100;
      rektangel.w = 100;

      SDL_SetRenderDrawColor(renderer,  rand() % 256,  rand() % 256,  rand() % 256, 255);
      SDL_RenderFillRect(renderer, &rektangel);
      SDL_RenderPresent(renderer);

      printf("Rektangel: x = %d ,y = %d, h = %d, w = %d\n", rektangel.x, rektangel.y, rektangel.h, rektangel.w);

      notPressed = 1;
      while(notPressed) {
	if(SDL_PollEvent(&event)) switch(event.type) {
	  case SDL_QUIT:
	    printf("Quit.\n");
	    notQuit = 0;
	    exit(EXIT_SUCCESS);
	    break;
	    
	  case SDL_MOUSEBUTTONDOWN:
	    
	    printf("Rektangel x: %d, y: %d,\nRektangel w: %d, h: %d\n Event x: %d, y: %d", rektangel.x, rektangel.y, rektangel.w, rektangel.h, event.button.x, event.button.y);
	    
	    if(event.button.button == SDL_BUTTON_LEFT && event.button.x > rektangel.x && event.button.x < rektangel.x + rektangel.w && event.button.y > rektangel.y && event.button.y < rektangel.y + rektangel.h) {
	      printf("Button pressed in rectangle.\n");
	      SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	      SDL_RenderPresent(renderer);
	      notPressed = 0;
	    }
	    else printf("%d: Button pressed.\n", time(NULL) - startTime);
	    
	    if(event.button.which == SDL_TOUCH_MOUSEID) printf("Touch input.\n");
	    break;
	    
	  default:
	    break;
	  }
	
      }
    }
  }
}
