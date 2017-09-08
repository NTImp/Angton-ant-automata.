#ifndef HEADER_H
#define HEADER_H

#include<stdio.h>
#include<SDL2/SDL.h>

#define TAB_SIZE 128
#define RND_SCALE 4

struct Ant {
	unsigned char dir;
	unsigned int x;
	unsigned int y;
} ant;

void ant_update();

char init_sdl();
char quit_sdl();
void print_screen();

unsigned char tab[TAB_SIZE][TAB_SIZE];
char *rule; 
char crule; //number of rules

unsigned char *cr;
unsigned char *cg;
unsigned char *cb;

SDL_Window* win;
SDL_Renderer* rnd;

#endif
