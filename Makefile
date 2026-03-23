# Compiler
CC = gcc

# Compiler flags
# -Wall: enables all compiler's warning messages
# -lm: links the math library (required for floor())
CFLAGS = -Wall -lm

# Target executable name
TARGET = star

# Source files
SRC = main.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(SRC) -o $(TARGET) $(CFLAGS)

clean:
	rm -f $(TARGET)

re: clean all