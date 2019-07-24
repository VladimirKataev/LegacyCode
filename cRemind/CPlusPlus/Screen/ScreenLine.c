#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

int main(int argc, char** argv){
	int heightBytes = 4;
	int widthBytes = 4;
	int* screen = calloc(heightBytes*widthBytes,8); //mk our l*w screen
	int mask = 2^heightBytes*widthBytes*3;						//for printing
	int y1 = 3;
	int y2 = 6;
	int x = 3;




	start = screen;
	for(int h =0; h < heightBytes*8; h++){
		for(int w = 0; w < widthBytes*8; w++){
				if(mask & start != 0){
					printf("#");

				}
				else{
					printf("-");
				}
				start += 1;
		}
		printf("|\n");
	}

}
