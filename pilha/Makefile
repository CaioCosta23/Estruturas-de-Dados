all: libpilha.a main.c
	gcc -g -o main/main main.c -lpilha -I src/ -L ./

build/%.o: src/%.c
	gcc -Wall -g -c -o $@ $<

libpilha.a: build/vector.o build/stack.o build/product.o
	ar rcs lib/libpilha.a build/vector.o build/stack.o build/product.o

clean:
	rm -rf main lib/*.a build/*.o main/main