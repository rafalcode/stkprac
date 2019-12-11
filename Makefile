CC=g++
CFLAGS=-g -Wall
INCS=-I/usr/include/stk
DBGCFLAGS=-g -Wall -DDBG
SPECLIBS=-lstk

# looking for uov? chekc the juegoca repository

EXECUTABLES=ex0 ex0v sineosc

ex0: ex0.cpp
	${CC} ${CFLAGS} $(INCS) -o $@ $^ $(SPECLIBS)
ex0v: ex0v.cpp
	${CC} ${CFLAGS} $(INCS) -o $@ $^ $(SPECLIBS)
sineosc: sineosc.cpp
	${CC} ${CFLAGS} $(INCS) -o $@ $^ $(SPECLIBS)

.PHONY: clean

clean:
	rm -f ${EXECUTABLES}
