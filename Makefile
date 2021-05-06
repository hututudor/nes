CC=gcc
LIBS=-lSDL2
OUTPUT=emulator
ROM=roms/hello.nes
SOURCES=src/*.c \
				src/bus/*.c \
				src/parser/*.c \
				src/cpu/*.c

run: build
	./$(OUTPUT) $(ROM)

build: 
	$(CC) $(SOURCES) -o $(OUTPUT) -g -Wall $(LIBS)

gdb: build
	gdb --args $(OUTPUT) $(ROM)

valgrind: build
	valgrind --leak-check=full \
		--show-leak-kinds=all \
		--track-origins=yes \
		--verbose \
		--log-file=valgrind-out.txt \
		./$(OUTPUT) $(ROM)

dump: build
	objdump $(OUTPUT) -S -j .text -Mintel

clean:
	rm $(OUTPUT)