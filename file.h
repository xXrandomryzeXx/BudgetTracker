#ifndef FILE_H
#define FILE_H
#include <stdio.h>

FILE *file;
int line_index;

int open_file();
void close_file();
void write_expense(const char* type, double amount);
double get_budget();
void get_line(char array[3][32]);
void get_data(char array[1024][3][32]);
#endif
