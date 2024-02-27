CC = gcc
FLAGS = -std=c17

TARGET = calculator.exe
SOURCES = calculator.c scanner.c stackOfDoublesModule.c
OBJECTS = $(SOURCES:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(FLAGS) -o $@ $^
scanner.o: scanner.c
	$(CC) -c scanner.c -o scanner.o $(FLAGS)

stackOfDoublesModule.o:stackOfDoublesModule.c
	$(CC) -c stackOfDoublesModule.c -o stackOfDoublesModule.o $(FLAGS)

clean:
	del /f $(TARGET) $(OBJECTS)

remake:
	make clean
	make