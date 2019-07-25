#include<stdio.h>
#include<stdlib.h>
int main (int argc, char* argv[]){
	int line1 = 0;
	int line2 = 0;
	int line3 = 0;
	int line4 = 0;
	int line5 = 0;
	int line6 = 0;
	int line7 = 0;
	int line8 = 0;
	int cursor = 16;

	char currentL;
	for(int i=1; i<argc; i++){
		char *arg = argv[i];
		char letter = arg[0];
		//currentL = argv[letter];
		line1 = line1 << 8;
		line2 = line2 << 8;
		line3 = line3 << 8;
		line4 = line4 << 8;
		line5 = line5 << 8;
		line6 = line6 << 8;
		line7 = line7 << 8;
		line8 = line8 << 8;

		if(letter == 'A'){		// 01234567
			line1 += 0b00000000000000000000000000001000;
			line2 += 0b00000000000000000000000000010100;
			line3 += 0b00000000000000000000000000100100;
			line4 += 0b00000000000000000000000000111100;
			line5 += 0b00000000000000000000000001000010;
			line6 += 0b00000000000000000000000001000010;
			line7 += 0b00000000000000000000000001000010;
			line8 += 0b00000000000000000000000000000000;
		}

		if(letter == 'B'){		// 01234567;
			line1 += 0b00000000000000000000000011111100;
			line2 += 0b00000000000000000000000010000010;
			line3 += 0b00000000000000000000000010000100;
			line4 += 0b00000000000000000000000010111100;
			line5 += 0b00000000000000000000000010000010;
			line6 += 0b00000000000000000000000010000010;
			line7 += 0b00000000000000000000000010000010;
			line8 += 0b00000000000000000000000011111100;
		}
		if(letter == 'C'){		// 01234567
			line1 += 0b00000000000000000000000000000110;
			line2 += 0b00000000000000000000000000010001;
			line3 += 0b00000000000000000000000000100000;
			line4 += 0b00000000000000000000000000100000;
			line5 += 0b00000000000000000000000000100000;
			line6 += 0b00000000000000000000000000010000;
			line7 += 0b00000000000000000000000000001001;
			line8 += 0b00000000000000000000000000000110;
		}
		if(letter == 'D'){		// 01234567
			line1 += 0b00000000000000000000000000111100;
			line2 += 0b00000000000000000000000001000010;
			line3 += 0b00000000000000000000000001000001;
			line4 += 0b00000000000000000000000001000001;
			line5 += 0b00000000000000000000000001000001;
			line6 += 0b00000000000000000000000001000001;
			line7 += 0b00000000000000000000000001000010;
			line8 += 0b00000000000000000000000001111100;
		}
	}

	unsigned int mask = 0b10000000000000000000000000000000;
	unsigned int strt = mask;
	for(int p = 0; p < 32; p++){
		if(mask & line1){printf("X");}
		else{printf("_");}
		mask = mask >>1;
	}
	printf("\n");
	mask = strt;
	for(int p = 0; p < 32; p++){
		if(mask & line2){printf("X");}
		else{printf("_");}
		mask = mask >>1;

	}
	printf("\n");
	mask = strt;
	for(int p = 0; p < 32; p++){
		if(mask & line3){printf("X");}
		else{printf("_");}
		mask = mask >>1;

	}
	printf("\n");
	mask = strt;
	for(int p = 0; p < 32; p++){
		if(mask & line4){printf("X");}
		else{printf("_");}
		mask = mask >>1;

	}
	printf("\n");
	mask = strt;
	for(int p = 0; p < 32; p++){
		if(mask & line5){printf("X");}
		else{printf("_");}
		mask = mask >>1;

	}
	printf("\n");
	mask = strt;
	for(int p = 0; p < 32; p++){
		if(mask & line6){printf("X");}
		else{printf("_");}
		mask = mask >>1;

	}
	printf("\n");
	mask = strt;
	for(int p = 0; p < 32; p++){
		if(mask & line7){printf("X");}
		else{printf("_");}
		mask = mask >>1;

	}
	printf("\n");
	mask = strt;
	for(int p = 0; p < 32; p++){
		if(mask & line8){printf("X");}
		else{printf("_");}
		mask = mask >>1;

	}
	printf("%d \n", line1);

	return 0;
}	
