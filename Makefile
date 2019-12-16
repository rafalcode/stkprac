CC=g++
CFLAGS=-g -Wall
INCS=-I/usr/include/stk
DBGCFLAGS=-g -Wall -DDBG
SPECLIBS=-lstk

EXECUTABLES=ex0 ex0v sineosc foursine

ex0: ex0.cpp
	${CC} ${CFLAGS} $(INCS) -o $@ $^ $(SPECLIBS)
ex0v: ex0v.cpp
	${CC} ${CFLAGS} $(INCS) -o $@ $^ $(SPECLIBS)
sineosc: sineosc.cpp
	${CC} ${CFLAGS} $(INCS) -o $@ $^ $(SPECLIBS)
foursine: foursine.cpp
	${CC} ${CFLAGS} $(INCS) -o $@ $^ $(SPECLIBS)

.PHONY: clean

clean:
	rm -f ${EXECUTABLES}
