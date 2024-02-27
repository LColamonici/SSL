CC=gcc
FLAGS= -std=c17
NOMBRE_EXE=main

all: $(NOMBRE_EXE)

histog1.o: histograma-1-enum-switch.c
	$(CC) -c histograma-1-enum-switch.c -o histog1.o $(FLAGS)

histog2.o: histograma-2-goto.c
	$(CC) -c histograma-2-goto.c -o histog2.o $(FLAGS)

histog3.o: histograma-3-rec.c
	$(CC) -c histograma-3-rec.c -o histog3.o $(FLAGS)

histog4.o: histograma-4-x.c
	$(CC) -c histograma-4-x.c -o histog4.o $(FLAGS)

$(NOMBRE_EXE): main.c histog1.o histog2.o histog3.o histog4.o
	$(CC) main.c histog1.o histog2.o histog3.o histog4.o -o $(NOMBRE_EXE) $(FLAGS)

clean: 
	del /f $(NOMBRE_EXE).exe *.o