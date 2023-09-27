#include "file.h"
#include <stdlib.h>
#include <time.h>
#include <string.h>

int open_file(){
	file = fopen("data.txt", "a+");
	
	if(file == NULL)
		return -1;
	line_index = 0;
	return 1;
}

void close_file(){
	fclose(file);
}

void write_expense(const char* type, double amount){
	time_t today_seconds = time(NULL);
	fprintf(file, "%ld|%s|%lf|\n", today_seconds, type, amount);
}

double get_budget(){
	if(line_index != 0)
		return -1.0;

	char line[10];
	fgets(line, 10, file);
	line_index++;
	return strtod(line, NULL);
}

void get_data(char array[1024][3][32]){
	int line_index = 0;
	char raw_line[128];
	int line_data_index = 0;
	int array_index = 0;

	int eof = 0;
	do{
		if(fgets(raw_line, 128, file) == NULL){
			eof = 1;
			break;
		}
		line_index++;
		
		char input_string[32];
		int input_string_index = 0;
		memset(input_string, '\0', 32);
		if(line_index > 2){
			for(int i = 0; i < 128; i++){
				if(raw_line[i] == '|'){
					strncpy(array[array_index][line_data_index], input_string, 32);	
					memset(input_string, '\0', 32);
					line_data_index++;
					input_string_index = 0;
					i++;
				}

				if(line_data_index > 2)
					break;

				input_string[input_string_index] = raw_line[i];
				input_string_index++;
			}		
			array_index++;

			if(array_index >= 1024)
				break;
			line_data_index = 0;
		}
	}while(!eof);
}
