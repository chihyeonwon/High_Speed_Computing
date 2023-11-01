//Makefile
foo: foo.o libprt.a
        cc -o foo foo.o -lprt -L.

libptr.a: prt.o
        ar cr libprt.a prt.o

prt.o: prt.c foo.h
        cc -c prt.c

foo.o: foo.c foo.h
        cc -c foo.c

clean:
        rm -f *.o

run:
        @ foo;echo $?