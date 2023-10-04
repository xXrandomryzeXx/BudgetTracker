#include <stdio.h> 
#include <string.h> 
int main(){
	double inputs[7] = {0, 2.5, 0.4, 3.0, 1.6, 5.0, 1.4};
	char graphic[10][70];
	memset(graphic, ' ', 10*70);

	double max_val = 0.0;
	
	for(int i = 0; i < 7; i++){
		if(inputs[i] > max_val)
			max_val = inputs[i];
	}

	double rel_num = 10 / max_val;

	for(int i = 0; i < 7; i++){
		double rel_height = 10 - inputs[i] * rel_num;
		if(rel_height > 0 && rel_height < 1) rel_height = 1;
	/*	for(int y = 10-1; y >= 10 - rel_height; y--){
			graphic[y][i*10] = '#';
		}*/		
		//graphic[10 - (int)rel_height][i*10] = '#';
		if(i < 6){
			int start_x = i*10;
			int next_x = start_x + 10;
			for(int x = start_x; x < next_x; x++){
			 	double target_y = 10 - (inputs[i+1] * rel_num);
				if(target_y > 0 && target_y < 1) target_y = 1;

				double diff = (target_y - rel_height) / 10;
				int y = (int)(rel_height + ((x - start_x) * diff));

				graphic[y][x]= '#';	
			}	
		}
	}
	printf("\n");
	for(int y = 0; y < 10; y++){
		for(int x = 0; x < 70; x++){
			printf("%c", graphic[y][x]);
		}
		printf("\n");
	}	
	return 0;
}
