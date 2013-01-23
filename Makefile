.c.o:   $*.h
	gcc -c $*.c

.cpp.o:	$*.h
	g++	-c $*.cpp

all:	ManipuladorStrings \
	Manipuladores


ManipuladorStrings:  ManipuladorStrings.o
	gcc -o $@ $^

Manipuladores:  Manipuladores.o
	gcc -o $@ $^

clean:
	rm *.o *.*~ *~	ManipuladorStrings \
			Manipuladores
