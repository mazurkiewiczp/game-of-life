#include "life.h"
#include "neighbors.h"
#include "draw.h"
#include "save.h"
#include "state.h"
#include "process_file.h"
#include "write_png_file.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ng - liczba generacji, m - dla co ktorej generacji ma powstac png */
void life(int **world, int N, int ng, int m){
	int x,y,i,j,k,q;
	int **tmp;
	char s[99];
	q=1;
	tmp=(int**)malloc(N*sizeof(int *));
	for(i=0; i<N; i++)
	{
		tmp[i]=(int*)malloc(N*sizeof(int));
	}

	for (i=0;i<N;i++)
		for (j=0;j<N;j++)
			tmp[i][j]=0;

	for (k=0;k<ng;k++){
		for (i=0;i<N;i++)
			for (j=0;j<N;j++)
				tmp[i][j]=neighbors(world,N,i,j);

		for (i=0;i<N;i++)
			for (j=0;j<N;j++){
				world[i][j]=state(tmp[i][j],world[i][j]);
			}
		if (q==m){
		sprintf(s,"out%d.png",k+1);		
		process_file(world,N);
		write_png_file(s,N);	
		q=1;
		}
		else q++;
	}
	//draw(world,N);	
	save(world,N);
}
