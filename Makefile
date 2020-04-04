CC=gcc
OUT=main

$(OUT): clean
	gcc -o $(OUT) source/*.c

clean:
	rm $(OUT)
