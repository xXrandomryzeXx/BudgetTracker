#include "input.h"
#include <stdio.h>

short get_menu_input(){
	short input;
	scanf("%hd", &input);
	return input;
}

double get_money_input(){
	double input;
	scanf("%lf", &input);
	return input;
}

void get_text_input(char string[256]){
	scanf("%256s", string);
}
