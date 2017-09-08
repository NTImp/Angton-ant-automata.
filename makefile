TARGET =  langton
CFLAGS = -lSDL2 -lSDL2main -std=c11
SRC = src/*.c

$(TARGET): $(SRC)
	gcc $(SRC) $(CFLAGS) -o  $(TARGET)
