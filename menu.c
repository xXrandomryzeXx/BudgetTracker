#include "menu.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "input.h"
#include "file.h"



double get_sum(time_t start, time_t end, char lines[1024][3][32]);

double get_average(time_t start, time_t end, char lines[1024][3][32]);

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
			double sum = 0;
			struct tm tm={0};
			tm.tm_year = 2023-1900;
			tm.tm_mon = 9 - 1;
			tm.tm_mday = 26;
			tm.tm_hour = 12;
			printf("Sum = %lf\n", get_sum(mktime(&tm), time(0), lines));
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
double get_sum(time_t start, time_t end, char lines[1024][3][32]){
	double sum = 0;
	for(int i = 0; i < 1024; i++){
		if(lines[i][0][0] != '\0'){
			time_t date = strtol(lines[i][0], NULL, 10);
			//printf("%s\n", asctime(localtime(&date)));
			if((start==0 || difftime(date, start) > 0) && (end==0 || difftime(end, date) > 0)){
				sum += strtod(lines[i][2], NULL);
			}
		}
		else break;
	}
	return sum;
}
double get_average(time_t start, time_t end, char lines[1024][3][32]){
	double sum = 0;
	int count = 0;
	for(int i = 0; i < 1024; i++){
		if(lines[i][0][0] != '\0'){
			sum += strtod(lines[i][2], NULL);
			count++;
		}
		else break;	
	}
	return sum/count;
}
