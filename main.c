#include <stdio.h>
#include "menu.h"

int main(){
	printf("\e[H\e[2J\e[3J");
	do{
		menu();
		//Get user input
		//Handle input
		//Save data
	}while(!exit_call);
    return 0;
}
