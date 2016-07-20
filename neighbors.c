#include "neighbors.h"
#include <stdio.h>

int neighbors(int** world, int N, int x, int y){
	int i,j,s=0;
	if (y-1>=0){
		if (x-1>=0 && world[x-1][y-1]==1) s++;
		if (world[x][y-1]==1) s++;
		if (x+1<N && world[x+1][y-1]==1) s++;
	}

	if (x-1>=0 && world[x-1][y]==1) s++;
	if (x+1<N && world[x+1][y]==1) s++;

	if (y+1<N){
		if (x-1>=0 && world[x-1][y+1]==1) s++;
		if (world[x][y+1]==1) s++;
		if (x+1<N && world[x+1][y+1]==1) s++;
	}

	return s;
}

