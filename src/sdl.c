#include"head.h"

SDL_Texture* screen;

char init_sdl()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	
	win = SDL_CreateWindow("langtom"
	,SDL_WINDOWPOS_CENTERED
	,SDL_WINDOWPOS_CENTERED
	,TAB_SIZE*RND_SCALE
	,TAB_SIZE*RND_SCALE
	,SDL_WINDOW_SHOWN);
	
	rnd = SDL_CreateRenderer(win,-1,SDL_RENDERER_SOFTWARE);
	SDL_RenderSetLogicalSize(rnd,TAB_SIZE,TAB_SIZE);

	screen = SDL_CreateTexture(rnd, SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_STREAMING, TAB_SIZE, TAB_SIZE);

	return 0;
}

char quit_sdl()
{
	SDL_DestroyTexture(screen);

	SDL_DestroyRenderer(rnd);
	SDL_DestroyWindow(win);

	SDL_Quit();
	return 0;
}

void print_screen(){
	Uint32* pixels = 0;
	int pitch = 0;

	SDL_LockTexture(screen, NULL, (void**) &pixels, &pitch);

	for(int i = 0; i < TAB_SIZE; i++){
		for(int e = 0; e < TAB_SIZE; e++){
			unsigned char cell = tab[i][e];
			
			Uint32 one = 1;
			if (*((char*)&one) != 1){
				*pixels = (cr[cell] << 24) | (cg[cell] << 16) | (cb[cell] << 8);
			} else {
				*pixels = cr[cell] | (cg[cell] << 8) | (cb[cell] << 16);
			}

			pixels++;
		}
	}

	SDL_UnlockTexture(screen);

	SDL_RenderCopy(rnd, screen, NULL, NULL);
}
