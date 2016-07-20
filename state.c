#include "state.h"
#include <stdio.h>

int state(int n, int s){
	if (s==0){ 
		if (n==3) return 1;
		else return 0;
	}
	if (s==1){
		if (n==2) return 1;
		if (n==3) return 1;
		else return 0;
	}
}
