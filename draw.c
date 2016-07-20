#include "draw.h"
#include <stdio.h>
#include <unistd.h>

void draw(int **world,int N){
	int i,j;

	//sleep(1);
	//system ("clear");

	for (i=0;i<N;i++){
		for (j=0;j<N;j++){
			if (world[i][j]==0) printf (".");
			else printf ("O");
		}
		printf ("\n");
	}
}
