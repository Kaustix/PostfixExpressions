LIBDIR = /usr/lib
TESTFLAGS = -lcppunit -ldl
CC = /usr/bin/g++
HEADERDIRS = ../include
CCFLAGS = -I $(HEADERDIRS) -std=c++0x
COMMONOBJS = PostfixExpr.o Tokenizer.o
MAINOBJS = main.o  
TESTOBJS = testMain.o

all: expr tests

expr: $(COMMONOBJS) $(MAINOBJS)
	${CC} -o $@ $^ -L$(LIBDIR)

tests: $(COMMONOBJS) $(TESTOBJS)
	${CC} -o $@ $^ -L$(LIBDIR) $(TESTFLAGS)

%.o : %.cc
	${CC} $(CCFLAGS) -c $^

.PHONY: clean
clean:
	rm -f *.o *~