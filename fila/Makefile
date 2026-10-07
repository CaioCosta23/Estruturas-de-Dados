all: libfila.a main.c
	gcc -g -o main/main main.c -lfila -I src/ -L ./

build/%.o: src/%.c
	gcc -Wall -g -c -o $@ $<

libfila.a: build/vector.o build/queue.o build/product.o
	ar rcs lib/libfila.a build/vector.o build/queue.o build/product.o

clean:
	rm -rf main lib/*.a build/*.o main/main
