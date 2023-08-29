#include "hej.h"

int main(void) {
  int startTime = time(NULL);
    
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
  
  if(SDL_CreateWindowAndRenderer(500, 500, 0 /* SDL_WINDOW_MAXIMIZED | SDL_WINDOW_GRESIZABnLE */, &screen, &renderer)) {
    exit(EXIT_FAILURE);
  }
  SDL_SetWindowTitle(screen, "Hej");

  srand((int)startTime);
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

      /* SDL_SetRenderDrawColor(renderer, rand() % 256, rand() % 256,  rand() % 256, 255); */
      /* SDL_RenderDrawRect(renderer, &rektangel); */
      
      SDL_SetRenderDrawColor(renderer,  rand() % 256,  rand() % 256,  rand() % 256, 255);
      /*      SDL_SetRenderDrawColor(renderer,  150,  150,  0, 255);*/
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
	    /*	    printf("%d: Default event\n", time(NULL) - startTime);*/
	    break;
	  }
	
      }
    }
  }
  
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(screen);
  exit(EXIT_SUCCESS);

}
