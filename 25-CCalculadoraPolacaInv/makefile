CC = gcc
CFLAGS = -std=c11

TARGET = mi_programa.exe
SOURCES = main.c funciones.c
OBJECTS = $(SOURCES:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	del $(TARGET) $(OBJECTS)