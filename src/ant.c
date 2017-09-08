#include"head.h"

void ant_update(){
	switch(ant.dir){
		case 0: //left
			ant.x = (ant.x+TAB_SIZE-1)%TAB_SIZE;
			break; 
		case 1: //up
			ant.y = (ant.y+TAB_SIZE-1)%TAB_SIZE;
			break; 
		case 2: //right
			ant.x = (ant.x+1)%TAB_SIZE;
			break; 
		case 3: //down
			ant.y = (ant.y+1)%TAB_SIZE;
			break; 
	}
	if(rule[tab[ant.y][ant.x]]){
		ant.dir = (ant.dir+1)%4;
	}else{
		ant.dir = (ant.dir+3)%4;
	}
	tab[ant.y][ant.x] = (tab[ant.y][ant.x]+1)%crule;
}
