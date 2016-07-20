gol: main.o life.o save.o draw.o neighbors.o state.o process_file.o write_png_file.o
	$(CC) -o gol main.o life.o save.o draw.o neighbors.o state.o process_file.o write_png_file.o -lpng

main.o: main.c life.h
	$(CC) -c main.c

life.o: life.c save.h life.h state.h neighbors.h draw.h process_file.h write_png_file.h
	$(CC) -c life.c

save.o: save.c save.h
	$(CC) -c save.c

draw.o: draw.c draw.h
	$(CC) -c draw.c

neighbors.o: neighbors.c neighbors.h
	$(CC) -c neighbors.c

state.o: state.c state.h
	$(CC) -c state.c

process_file.o: process_file.c process_file.h
	$(CC) -c process_file.c -lpng

write_png_file.o: write_png_file.c write_png_file.h
	$(CC) -c write_png_file.c -lpng 

