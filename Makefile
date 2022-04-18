CC = g++
CFLAGS = -g -Wall -Wextra
TARGET = main
all: $(TARGET)

Weight.o: Weight.cpp Weight.h
	$(CC) $(CFLAGS) -c Weight.cpp

main.o: main.cpp Weight.cpp Weight.h
	$(CC) $(CFLAGS) -c main.cpp

main: Weight.o main.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o Weight.o

clean:
	rm -f $(TARGET) *.o