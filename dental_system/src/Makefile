CC = gcc
CFLAGS = -std=c17 -Wall -Wextra -O2

SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
TARGET = dental_system

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

clean:
	rm -f $(OBJ) $(TARGET)
