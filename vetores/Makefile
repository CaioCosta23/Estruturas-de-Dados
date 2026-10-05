all: libvector.a main.c
	gcc -g -o main main.c -lvector - I src/ -L ./

build/%.o: src/%.c
	gcc -Wall -g -c -o $@ $<

libvector.a: build/vector.o
	ar rcs lib/libvector.a build/vector.o

clean:
	rm -rf main lib/*.a build *.o