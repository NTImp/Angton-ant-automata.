#include<malloc.h>
#include"head.h"

void read_rule(char * rul){
	crule = 0;
	for(char*r = rul;*r=='r'||*r=='l';r++)
		crule++;

	if(crule>1){
		rule = malloc(sizeof(char)* crule);
		for(int i=0;i<crule;i++){
			rule[i] = (rul[i]=='r');
		}
	}else{
		crule = 2;
		rule =  malloc(sizeof(char)*2);
		rule[0] = 0;
		rule[1] = 1;
	}
	
	cr = malloc(crule);
	cg = malloc(crule);
	cb = malloc(crule);

	for(int i=0;i<crule;i++){
		cr[i] = rand()*i;
		cg[i] = rand()*i;
		cb[i] = rand()*i;
		if(i==1){	
		cr[i] = 255;
		cg[i] = 255;
		cb[i] = 255;
		}
	}
}

void init_tab(){
	for(int i=0;i<TAB_SIZE;i++)
		for(int e=0;e<TAB_SIZE;e++)
			tab[e][i] = 0;
}

int main(int argc, char **argv){
	if(argc>1) read_rule(argv[1]);
	else read_rule("lr");

	init_tab();

	ant.x = TAB_SIZE/2;
	ant.y = TAB_SIZE/2;
	ant.dir = 0;

	char running = 1;
	SDL_Event ev;

	init_sdl();

	SDL_SetRenderDrawColor(rnd,0,0,0,0);
	SDL_RenderClear(rnd);

	while(running){
		while(SDL_PollEvent(&ev)){
			switch(ev.type){
				case SDL_QUIT:
					running = 0;
					break;
			}
		}
		ant_update();

		print_screen();

		SDL_RenderPresent(rnd);
	}

	free(rule);
	free(cr);
	free(cg);
	free(cb);

	quit_sdl();

	return 0;
}
