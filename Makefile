CC=gcc
SOURCES=./sources/*.c
OUTPUT=./build

main: clean
	gcc -o $(OUTPUT)/main $(SOURCES)

clean:
	rm -rf $(OUTPUT)/main

all: main
	(cd $(OUTPUT) && ./main)
