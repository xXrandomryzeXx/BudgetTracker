#include "menu.h"
#include <stdio.h>
#include "input.h"
#include "file.h"

short exit_call = 0;
short current_menu = 0; // 0 - First menu

void clear_console(){
	printf("\e[H\e[2J\e[3J");
}

void menu(){
	if(!open_file()){
		printf("Could not open data.txt");
		exit_call = 1;
	}

	switch(current_menu){
		case 0:
			printf("Budget Tracker menu:\n");
			printf("Weekly budget -> %lf\n", get_budget());
			printf("1. Add expense\n");
			printf("2. Edit budget\n");
			printf("3. View data\n");
			printf("4. Exit\n");
			printf("\nChoose an option\n");
			current_menu = get_menu_input();
			break;
		case 1:
			clear_console();
			printf("Add daily expense\n");
			printf("Enter the type of the expense: ");
			char expense_type[32];
			get_text_input(expense_type);
			printf("Enter the expense amount: ");
			double expense_amount = get_money_input();

			write_expense(expense_type, expense_amount);
			current_menu = 0;
			clear_console();
			
			break;
	   	case 2:
			break;
		case 3:
			clear_console();
			char lines[1024][3][32];
			get_data(lines);
			for(int i = 0; i < 1024; i++){
				 if(lines[i][0][0] != '\0') printf("Type of expense -> %s cost -> %s\n",lines[i][1], lines[i][2]);
				 else break;
			}
			current_menu = 0;
			break;
		case 4:
			close_file();
			exit_call = 1;
			break;
		default:
			printf("\n Enter a valid choice \n");
	}
}
