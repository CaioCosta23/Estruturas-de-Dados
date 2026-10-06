all: libpilhafila.a main.c
	gcc -g -o main/main main.c -lpilhafila -I src/ -L ./

build/%.o: src/%.c
	gcc -Wall -g -c -o $@ $<

libpilhafila.a: build/vector.o build/stack.o build/queue.o build/product.o
	ar rcs lib/libpilhafila.a build/vector.o build/stack.o build/queue.o build/product.o

clean:
	rm -rf main lib/*.a build/*.o main/main
