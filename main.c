#include "life.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

	int N,i,j,x,y,ng=10,p=1;

	if (argc<=1) {printf("Zbyt malo argumentow\n"); return 0;}
	if (argc==3){ ng=atoi(argv[argc-2]);}
	if (argc>3) {printf("Zbyt wiele argumentow\n"); return 0;}

	int **world;
	FILE *in; 
	if((in = fopen (argv[argc-1], "r"))==NULL){printf ("Nie moge odczytac pliku\n"); return 0;}
	fscanf(in,"%d",&N);

	world=(int**)malloc(N*sizeof(int *));
	for(i=0; i<N; i++)
	{
		world[i]=(int*)malloc(N*sizeof(int));
	}

	for (i=0;i<N;i++)
		for (j=0;j<N;j++)
			world[i][j]=0;

	while (feof(in)==0){
		fscanf(in,"%d",&x);
		fscanf(in,"%d",&y);
		if (x < 1 || y < 1){printf ("Bledne dane (wspolrzedne powinny byc liczbami calkowitymi dodatnimi)\n"); return 0;}		
		world[x-1][y-1]=1;
	}

	life(world,N,ng,p);

	return 0;
}
