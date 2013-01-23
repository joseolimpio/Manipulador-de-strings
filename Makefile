all: ManipuladorStrings

ManipuladorStrings: ManipuladorStrings.o Manipuladores.o 
  gcc	ManipuladorStrings.o Manipuladores.o  -o ManipuladorStrings

ManipuladorStrings.o: ManipuladorStrings.c
	gcc -c ManipuladorStrings.c

Manipuladores.o: Manipuladores.h
	gcc -c Manipuladores.h

clean: 
	rm -rf *o ManipuladorStrings	
