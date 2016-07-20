#include "process_file.h"

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

#include <png.h>

int x, y;

int width, height;
png_byte color_type;
png_byte bit_depth;

png_structp png_ptr;
png_infop info_ptr;
int number_of_passes;
png_bytep * row_pointers;

void process_file(int **world, int N) {
	int i,j;
	width=height=N;
	bit_depth = 8;
	color_type = PNG_COLOR_TYPE_GRAY;

	number_of_passes = 7;
	row_pointers = (png_bytep*) malloc(sizeof(png_bytep) * height);
	for (y=0; y<height; y++)
		row_pointers[y] = (png_byte*) malloc(sizeof(png_byte) * width);

	for (y=0; y<N; y++) {
		png_byte* row = row_pointers[y];
		for (x=0; x<N; x++) {
			if(world[y][x]==1) row[x] = 0;
			else row[x]=255;
		}
	}
}
