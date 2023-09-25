#include "menu.h"
#include <stdio.h>
#include "input.h"

short exit_call = 0;
short current_menu = 0; // 0 - First menu

void menu(){
	switch(current_menu){
		case 0:
			printf("Budget Tracker menu:\n");
			printf("1. Add expense\n");
			printf("2. Edit budget\n");
			printf("3. View data\n");
			printf("4. Exit\n");
			printf("\nChoose an option\n");
			current_menu = get_menu_input();
			break;
		case 1:
			printf("\e[H\e[2J\e[3J");
			printf("Add daily expense\n");
			printf("Enter the type of the expense: ");
			char expense_type[256];
			get_text_input(expense_type);
			printf("Enter the expense amount: ");
			double expense_amount = get_money_input();

			printf("%s : %f\n", expense_type, expense_amount);
			exit_call = 1;
			
			break;
	   	case 2:
			break;
		case 3:
			break;
		case 4:
			exit_call = 1;
			break;
		default:
			printf("\n Enter a valid choice \n");
	}
}
