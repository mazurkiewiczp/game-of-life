#include "save.h"
#include <stdio.h>

#define SAVEFILE "last"

void save(int **world, int N){
	int i,j;
	FILE *s;
	s = fopen (SAVEFILE, "w");
	fprintf (s,"%d\n\n",N);

	for (j=0;j<N;j++)
		for (i=0;i<N;i++){
			if (world[i][j]==1) fprintf(s,"%d %d\n",i+1,j+1);	
		}

	fclose(s);
}
