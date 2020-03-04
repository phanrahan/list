DESTDIR=	../..
DESTINCDIR=	${DESTDIR}/include
DESTLIBDIR=	${DESTDIR}/lib

COPTS= -g
CFLAGS = ${COPTS}
LDFLAGS = 

NAME=	ph
LIB=	$(DESTLIBDIR)/lib${NAME}.a
OBJS =  list.o
SRCS =  list.c 
PUBHDRS=list.h
HDRS =	${PUBHDRS}

.c.o:
	${CC} ${CFLAGS} -c $*.c

all:	${LIB}

test:	test.o ${LIB}
	cc -g -o test test.o ${LIB}

install: $(LIB)
	mv ${LIB} ${DESTLIBDIR}
	cp ${PUBHDRS} ${DESTINCDIR}

get:
	sccs get ${REV} ${SRCS} ${HDRS}
	cp ${PUBHDRS} ${DESTINCDIR}

clean:
	rm -fr test *.out *.o *.a tags *.ln

tags:
	ctags ${SRCS} ${HDRS}

shar:
	shar Makefile ${SRCS} $HDRS} > ${NAME}.shar

${LIB}: ${OBJS}
	ar rc ${LIB} ${OBJS} 

# DO NOT DELETE THIS LINE
# make depend REWRITES EVERYTHING FROM HERE ON
#
list.o:	list.h
# IF YOU PUT STUFF HERE IT WILL GO AWAY
