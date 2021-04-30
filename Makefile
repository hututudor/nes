CC=gcc
OUTPUT=emulator
SOURCES=src/*.c \
				src/bus/*.c

run: build
	./$(OUTPUT) roms/test.nes

build: 
	$(CC) $(SOURCES) -o $(OUTPUT) -g -Wall

gdb: build
	gdb --args $(OUTPUT) roms/test.nes

valgrind: build
	valgrind --leak-check=full \
		--show-leak-kinds=all \
		--track-origins=yes \
		--verbose \
		--log-file=valgrind-out.txt \
		./$(OUTPUT) roms/test.nes

dump: build
	objdump $(OUTPUT) -S -j .text -Mintel

clean:
	rm $(OUTPUT)