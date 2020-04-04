CC=gcc
SOURCES=./sources/*.c
OUTPUT=./build

main: clean
	gcc -o $(OUTPUT)/main $(SOURCES)

clean:
	rm -rf $(OUTPUT)/main

run:
	(cd $(OUTPUT) && ./main)

all: main run
